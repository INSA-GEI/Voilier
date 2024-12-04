#ifndef TESTI2CSPIVIEW_HPP
#define TESTI2CSPIVIEW_HPP

#include <gui_generated/testi2cspi_screen/TestI2CSPIViewBase.hpp>
#include <gui/testi2cspi_screen/TestI2CSPIPresenter.hpp>

class TestI2CSPIView : public TestI2CSPIViewBase
{
public:
    TestI2CSPIView();
    virtual ~TestI2CSPIView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TESTI2CSPIVIEW_HPP
