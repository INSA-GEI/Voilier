#include <gui/rotationvoilier_screen/RotationVoilierView.hpp>

RotationVoilierView::RotationVoilierView()
{

}

void RotationVoilierView::setupScreen()
{
    RotationVoilierViewBase::setupScreen();
}

void RotationVoilierView::tearDownScreen()
{
    RotationVoilierViewBase::tearDownScreen();
}

void RotationVoilierView::ButtonMessagesClicked()
{

}

void RotationVoilierView::sliderRotationChanged(int value)
{
	rotationValue=value;
	rotationValue=(rotationValue-50)*2;
	rotationValue = -rotationValue;

	textRotationSpeed.invalidate();
	Unicode::snprintf(textRotationSpeedBuffer,TEXTROTATIONSPEED_SIZE,"%d",abs(rotationValue));
}

void RotationVoilierView::sliderRotationReleased(int value)
{
	rotationValue=0;

	sliderRotation.setValue(50);
	textRotationSpeed.invalidate();
	Unicode::snprintf(textRotationSpeedBuffer,TEXTROTATIONSPEED_SIZE,"%d",rotationValue);

	circleRotation.invalidate();
	circleRotation.setArc(110, 250);
	circleRotation.invalidate();
}

void RotationVoilierView::handleTickEvent()
{
	if (rotationValue!=0)
	{
		int arcStart, arcEnd;

		angleAdd=rotationValue/6;
		if (angleAdd==0)
		{
			if (rotationValue<0) angleAdd=-1;
			else  angleAdd=1;
		}

		arcStart = circleRotation.getArcStart() + angleAdd;
		arcEnd = circleRotation.getArcEnd() +angleAdd;

		if (arcEnd>=360)
		{
			arcEnd-=360;
			 arcStart-=360;
		}

		circleRotation.invalidate();
		circleRotation.setArc(arcStart, arcEnd);
		circleRotation.invalidate();
	}
}

