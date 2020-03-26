/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TESTORIENTATIONVOILEVIEWBASE_HPP
#define TESTORIENTATIONVOILEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/testorientationvoile_screen/TestOrientationVoilePresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>

class TestOrientationVoileViewBase : public touchgfx::View<TestOrientationVoilePresenter>
{
public:
    TestOrientationVoileViewBase();
    virtual ~TestOrientationVoileViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void buttonReturnClicked()
    {
        // Override and implement this function in TestOrientationVoile
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
    touchgfx::Callback<TestOrientationVoileViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // TESTORIENTATIONVOILEVIEWBASE_HPP
