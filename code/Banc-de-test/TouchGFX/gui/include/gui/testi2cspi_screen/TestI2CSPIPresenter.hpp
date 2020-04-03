#ifndef TESTI2CSPIPRESENTER_HPP
#define TESTI2CSPIPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestI2CSPIView;

class TestI2CSPIPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestI2CSPIPresenter(TestI2CSPIView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~TestI2CSPIPresenter() {};

private:
    TestI2CSPIPresenter();

    TestI2CSPIView& view;
};

#endif // TESTI2CSPIPRESENTER_HPP
