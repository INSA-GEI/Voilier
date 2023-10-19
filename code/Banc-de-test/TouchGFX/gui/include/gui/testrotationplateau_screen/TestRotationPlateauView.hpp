#ifndef TESTROTATIONPLATEAUVIEW_HPP
#define TESTROTATIONPLATEAUVIEW_HPP

#include <gui_generated/testrotationplateau_screen/TestRotationPlateauViewBase.hpp>
#include <gui/testrotationplateau_screen/TestRotationPlateauPresenter.hpp>

class TestRotationPlateauView : public TestRotationPlateauViewBase
{
public:
    TestRotationPlateauView();
    virtual ~TestRotationPlateauView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TESTROTATIONPLATEAUVIEW_HPP
