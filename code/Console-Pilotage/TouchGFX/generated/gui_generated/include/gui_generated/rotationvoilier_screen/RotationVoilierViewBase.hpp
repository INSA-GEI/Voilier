/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ROTATIONVOILIERVIEWBASE_HPP
#define ROTATIONVOILIERVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/rotationvoilier_screen/RotationVoilierPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class RotationVoilierViewBase : public touchgfx::View<RotationVoilierPresenter>
{
public:
    RotationVoilierViewBase();
    virtual ~RotationVoilierViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void ButtonMessagesClicked()
    {
        // Override and implement this function in RotationVoilier
    }

    virtual void sliderRotationChanged(int value)
    {
        // Override and implement this function in RotationVoilier
    }

    virtual void sliderRotationReleased(int value)
    {
        // Override and implement this function in RotationVoilier
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image imageBg;
    touchgfx::ButtonWithIcon buttonMessages;
    touchgfx::Image imageRotation;
    touchgfx::Image imageRotationIcon;
    touchgfx::Slider sliderRotation;
    touchgfx::Circle circleRotation;
    touchgfx::PainterRGB888 circleRotationPainter;
    touchgfx::Image imageRotBg;
    touchgfx::TextAreaWithOneWildcard textRotationSpeed;
    touchgfx::Image imageRotLeft;
    touchgfx::Image imageRotRight;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTROTATIONSPEED_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textRotationSpeedBuffer[TEXTROTATIONSPEED_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<RotationVoilierViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<RotationVoilierViewBase, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<RotationVoilierViewBase, const touchgfx::Slider&, int> sliderValueConfirmedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // ROTATIONVOILIERVIEWBASE_HPP