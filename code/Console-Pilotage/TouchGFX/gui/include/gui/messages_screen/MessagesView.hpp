#ifndef MESSAGESVIEW_HPP
#define MESSAGESVIEW_HPP

#include <gui_generated/messages_screen/MessagesViewBase.hpp>
#include <gui/messages_screen/MessagesPresenter.hpp>
#include <string>

class MessagesView : public MessagesViewBase
{
public:
    MessagesView();
    virtual ~MessagesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void buttonMessagesClicked();
    virtual void buttonWipeClicked();
protected:

    Unicode::UnicodeChar messageTxt[1500];
};

#endif // MESSAGESVIEW_HPP
