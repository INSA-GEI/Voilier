#ifndef TESTCOMPLETPRESENTER_HPP
#define TESTCOMPLETPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestCompletView;

class TestCompletPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestCompletPresenter(TestCompletView& v);

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

    virtual ~TestCompletPresenter() {};

private:
    TestCompletPresenter();

    TestCompletView& view;
};

#endif // TESTCOMPLETPRESENTER_HPP
