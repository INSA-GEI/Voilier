/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/testadc_screen/TestADCViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

TestADCViewBase::TestADCViewBase() :
    buttonCallback(this, &TestADCViewBase::buttonCallbackHandler)
{

    imageBg.setXY(0, 0);
    imageBg.setBitmap(touchgfx::Bitmap(BITMAP_GREEN_POLYGONS_BACKGROUND_480X272_ID));

    textArea1.setXY(219, 111);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID12));

    buttonReturn.setXY(10, 230);
    buttonReturn.setBitmaps(touchgfx::Bitmap(BITMAP_ICONS8_GO_BACK_60_ID), touchgfx::Bitmap(BITMAP_ICONS8_GO_BACK_60_ID));
    buttonReturn.setAction(buttonCallback);

    add(imageBg);
    add(textArea1);
    add(buttonReturn);
}

void TestADCViewBase::setupScreen()
{

}

void TestADCViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonReturn)
    {
        //InteractionButtonReturnClicked
        //When buttonReturn clicked call virtual function
        //Call buttonReturnClicked
        buttonReturnClicked();

        //InteractionReturnToMenu
        //When InteractionButtonReturnClicked completed change screen to Menu
        //Go to Menu with screen transition towards West
        application().gotoMenuScreenSlideTransitionWest();
    }
}
