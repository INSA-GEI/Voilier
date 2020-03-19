#ifndef ROTATIONVOILIERVIEW_HPP
#define ROTATIONVOILIERVIEW_HPP

#include <gui_generated/rotationvoilier_screen/RotationVoilierViewBase.hpp>
#include <gui/rotationvoilier_screen/RotationVoilierPresenter.hpp>

class RotationVoilierView : public RotationVoilierViewBase
{
public:
    RotationVoilierView();
    virtual ~RotationVoilierView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void ButtonMessagesClicked();
    virtual void sliderRotationChanged(int value);
    virtual void sliderRotationReleased(int value);
    virtual void handleTickEvent();
protected:
    int rotationValue=0;
    int angleAdd=0;
};

#endif // ROTATIONVOILIERVIEW_HPP
