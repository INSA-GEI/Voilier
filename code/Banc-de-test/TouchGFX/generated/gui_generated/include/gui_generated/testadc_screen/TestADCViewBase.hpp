/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TESTADCVIEWBASE_HPP
#define TESTADCVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/testadc_screen/TestADCPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>

class TestADCViewBase : public touchgfx::View<TestADCPresenter>
{
public:
    TestADCViewBase();
    virtual ~TestADCViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void buttonReturnClicked()
    {
        // Override and implement this function in TestADC
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image imageBg;
    touchgfx::TextArea textArea1;
    touchgfx::Button buttonReturn;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TestADCViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // TESTADCVIEWBASE_HPP
