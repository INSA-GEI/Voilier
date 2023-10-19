#ifndef TESTUARTVIEW_HPP
#define TESTUARTVIEW_HPP

#include <gui_generated/testuart_screen/TestUartViewBase.hpp>
#include <gui/testuart_screen/TestUartPresenter.hpp>

class TestUartView : public TestUartViewBase
{
public:
    TestUartView();
    virtual ~TestUartView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TESTUARTVIEW_HPP
