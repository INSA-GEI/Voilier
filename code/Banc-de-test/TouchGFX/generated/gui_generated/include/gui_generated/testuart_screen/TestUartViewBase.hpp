/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TESTUARTVIEWBASE_HPP
#define TESTUARTVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/testuart_screen/TestUartPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class TestUartViewBase : public touchgfx::View<TestUartPresenter>
{
public:
    TestUartViewBase();
    virtual ~TestUartViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void buttonWipeClicked()
    {
        // Override and implement this function in TestUart
    }

    virtual void buttonReturnClicked()
    {
        // Override and implement this function in TestUart
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image imageBg;
    touchgfx::ButtonWithIcon buttonWipe;
    touchgfx::TextAreaWithOneWildcard textMessages;
    touchgfx::Button buttonReturn;
    touchgfx::TextArea textArea1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTMESSAGES_SIZE = 1500;
    touchgfx::Unicode::UnicodeChar textMessagesBuffer[TEXTMESSAGES_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TestUartViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // TESTUARTVIEWBASE_HPP