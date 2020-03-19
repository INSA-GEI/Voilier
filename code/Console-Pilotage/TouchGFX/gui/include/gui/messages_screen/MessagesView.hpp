#ifndef MESSAGESVIEW_HPP
#define MESSAGESVIEW_HPP

#include <gui_generated/messages_screen/MessagesViewBase.hpp>
#include <gui/messages_screen/MessagesPresenter.hpp>

class MessagesView : public MessagesViewBase
{
public:
    MessagesView();
    virtual ~MessagesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MESSAGESVIEW_HPP
