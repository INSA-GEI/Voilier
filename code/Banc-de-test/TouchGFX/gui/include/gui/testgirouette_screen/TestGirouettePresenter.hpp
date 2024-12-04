#ifndef TESTGIROUETTEPRESENTER_HPP
#define TESTGIROUETTEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestGirouetteView;

class TestGirouettePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestGirouettePresenter(TestGirouetteView& v);

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

    virtual ~TestGirouettePresenter() {};

private:
    TestGirouettePresenter();

    TestGirouetteView& view;
};

#endif // TESTGIROUETTEPRESENTER_HPP
