#ifndef TESTUARTPRESENTER_HPP
#define TESTUARTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestUartView;

class TestUartPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestUartPresenter(TestUartView& v);

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

    virtual ~TestUartPresenter() {};

private:
    TestUartPresenter();

    TestUartView& view;
};

#endif // TESTUARTPRESENTER_HPP
