#ifndef TESTROTATIONPLATEAUPRESENTER_HPP
#define TESTROTATIONPLATEAUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestRotationPlateauView;

class TestRotationPlateauPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestRotationPlateauPresenter(TestRotationPlateauView& v);

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

    virtual ~TestRotationPlateauPresenter() {};

private:
    TestRotationPlateauPresenter();

    TestRotationPlateauView& view;
};

#endif // TESTROTATIONPLATEAUPRESENTER_HPP
