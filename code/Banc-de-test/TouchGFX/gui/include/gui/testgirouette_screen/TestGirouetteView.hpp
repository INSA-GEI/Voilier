#ifndef TESTGIROUETTEVIEW_HPP
#define TESTGIROUETTEVIEW_HPP

#include <gui_generated/testgirouette_screen/TestGirouetteViewBase.hpp>
#include <gui/testgirouette_screen/TestGirouettePresenter.hpp>

class TestGirouetteView : public TestGirouetteViewBase
{
public:
    TestGirouetteView();
    virtual ~TestGirouetteView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TESTGIROUETTEVIEW_HPP
