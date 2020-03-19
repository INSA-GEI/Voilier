/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MESSAGESVIEWBASE_HPP
#define MESSAGESVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/messages_screen/MessagesPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class MessagesViewBase : public touchgfx::View<MessagesPresenter>
{
public:
    MessagesViewBase();
    virtual ~MessagesViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void ButtonMessagesClicked()
    {
        // Override and implement this function in Messages
    }

    virtual void buttonWipeClicked()
    {
        // Override and implement this function in Messages
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image imageBg;
    touchgfx::ButtonWithIcon buttonRotation;
    touchgfx::Image imageMessages;
    touchgfx::Image imageMessagesIcon;
    touchgfx::Image imageMessageBoxBg;
    touchgfx::TextAreaWithOneWildcard textMessages;
    touchgfx::ButtonWithIcon buttonWipe;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTMESSAGES_SIZE = 1500;
    touchgfx::Unicode::UnicodeChar textMessagesBuffer[TEXTMESSAGES_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MessagesViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MESSAGESVIEWBASE_HPP
