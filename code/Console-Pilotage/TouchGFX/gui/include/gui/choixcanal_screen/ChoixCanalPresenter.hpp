#ifndef CHOIXCANALPRESENTER_HPP
#define CHOIXCANALPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ChoixCanalView;

class ChoixCanalPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ChoixCanalPresenter(ChoixCanalView& v);

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

    virtual ~ChoixCanalPresenter() {};

private:
    ChoixCanalPresenter();

    ChoixCanalView& view;
};

#endif // CHOIXCANALPRESENTER_HPP
