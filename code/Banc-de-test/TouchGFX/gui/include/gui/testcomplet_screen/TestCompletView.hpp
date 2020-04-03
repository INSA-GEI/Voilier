#ifndef TESTCOMPLETVIEW_HPP
#define TESTCOMPLETVIEW_HPP

#include <gui_generated/testcomplet_screen/TestCompletViewBase.hpp>
#include <gui/testcomplet_screen/TestCompletPresenter.hpp>

class TestCompletView : public TestCompletViewBase
{
public:
    TestCompletView();
    virtual ~TestCompletView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TESTCOMPLETVIEW_HPP
