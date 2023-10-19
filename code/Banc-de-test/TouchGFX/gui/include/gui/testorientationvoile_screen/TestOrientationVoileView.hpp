#ifndef TESTORIENTATIONVOILEVIEW_HPP
#define TESTORIENTATIONVOILEVIEW_HPP

#include <gui_generated/testorientationvoile_screen/TestOrientationVoileViewBase.hpp>
#include <gui/testorientationvoile_screen/TestOrientationVoilePresenter.hpp>

class TestOrientationVoileView : public TestOrientationVoileViewBase
{
public:
    TestOrientationVoileView();
    virtual ~TestOrientationVoileView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TESTORIENTATIONVOILEVIEW_HPP
