#ifndef CHOIXCANALVIEW_HPP
#define CHOIXCANALVIEW_HPP

#include <gui_generated/choixcanal_screen/ChoixCanalViewBase.hpp>
#include <gui/choixcanal_screen/ChoixCanalPresenter.hpp>

class ChoixCanalView : public ChoixCanalViewBase
{
public:
    ChoixCanalView();
    virtual ~ChoixCanalView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CHOIXCANALVIEW_HPP
