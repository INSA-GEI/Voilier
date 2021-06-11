#ifndef MESSAGESPRESENTER_HPP
#define MESSAGESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MessagesView;

class MessagesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MessagesPresenter(MessagesView& v);

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

    virtual ~MessagesPresenter() {};

private:
    MessagesPresenter();

    MessagesView& view;
};

#endif // MESSAGESPRESENTER_HPP
