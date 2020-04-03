#ifndef TESTADCVIEW_HPP
#define TESTADCVIEW_HPP

#include <gui_generated/testadc_screen/TestADCViewBase.hpp>
#include <gui/testadc_screen/TestADCPresenter.hpp>

class TestADCView : public TestADCViewBase
{
public:
    TestADCView();
    virtual ~TestADCView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TESTADCVIEW_HPP
