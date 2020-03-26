#ifndef TESTORIENTATIONVOILEPRESENTER_HPP
#define TESTORIENTATIONVOILEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestOrientationVoileView;

class TestOrientationVoilePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestOrientationVoilePresenter(TestOrientationVoileView& v);

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

    virtual ~TestOrientationVoilePresenter() {};

private:
    TestOrientationVoilePresenter();

    TestOrientationVoileView& view;
};

#endif // TESTORIENTATIONVOILEPRESENTER_HPP
