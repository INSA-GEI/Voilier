#include <gui/rotationvoilier_screen/RotationVoilierView.hpp>

extern "C" {
#include "xbee.h"
}

#include <stdio.h>
#include <string.h>


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
	//char strbuf[20];

	rotationValue=value;
	rotationValue=(rotationValue-50)*2;
	rotationValue = -rotationValue;

	textRotationSpeed.invalidate();
	Unicode::snprintf(textRotationSpeedBuffer,TEXTROTATIONSPEED_SIZE,"%d",abs(rotationValue));

	if (!circleRotation.isVisible()) circleRotation.setVisible(true);
	//sprintf(strbuf,"ROT=%i\r",rotationValue);
	//XbeeWriteData((uint8_t *)strbuf, strlen(strbuf));
	XbeeSetRotation(rotationValue);
}

void RotationVoilierView::sliderRotationReleased(int value)
{
	//char strbuf[20];

	rotationValue=0;

	sliderRotation.setValue(50);
	textRotationSpeed.invalidate();
	Unicode::snprintf(textRotationSpeedBuffer,TEXTROTATIONSPEED_SIZE,"%d",rotationValue);

	circleRotation.invalidate();
	circleRotation.setArc(180, 180);
	circleRotation.setVisible(false);
	circleRotation.invalidate();

	rotationAnimate=0;

	//sprintf(strbuf,"ROT=0\r");
	//XbeeWriteData((uint8_t *)strbuf, strlen(strbuf));
	XbeeSetRotation(rotationValue);
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

		if (rotationAnimate==1)
		{
			/* fait bouger l'arc de cercle */
			arcStart = circleRotation.getArcStart() + angleAdd;
			arcEnd = circleRotation.getArcEnd() +angleAdd;

			if (arcEnd>=360)
			{
				arcEnd-=360;
				arcStart-=360;
			}
		}
		else
		{
			/* agrandi l'arc de cercle */
			if (rotationValue>0)
			{
				arcStart = circleRotation.getArcStart() + angleAdd;
				arcEnd = circleRotation.getArcEnd();
			}
			else
			{
				arcStart = circleRotation.getArcStart() ;
				arcEnd = circleRotation.getArcEnd()+ angleAdd;
			}

			if (arcStart-arcEnd>=60) rotationAnimate=1;
		}

		circleRotation.invalidate();
		circleRotation.setArc(arcStart, arcEnd);
		circleRotation.invalidate();
	}
}

