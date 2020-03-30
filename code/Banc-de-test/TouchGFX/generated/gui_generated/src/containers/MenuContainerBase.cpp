/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/MenuContainerBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

MenuContainerBase::MenuContainerBase()
{
    setWidth(120);
    setHeight(88);
    image.setXY(36, 2);
    image.setBitmap(touchgfx::Bitmap(BITMAP_ICONS8_COMPASS_48_ID));

    textArea.setPosition(0, 50, 120, 38);
    textArea.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea.setLinespacing(0);
    Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID9).getText());
    textArea.setWildcard(textAreaBuffer);
    textArea.setTypedText(touchgfx::TypedText(T_SINGLEUSEID8));

    add(image);
    add(textArea);
}

void MenuContainerBase::initialize()
{

}