#include <gui/messages_screen/MessagesView.hpp>

MessagesView::MessagesView()
{

}

void MessagesView::setupScreen()
{
	MessagesViewBase::setupScreen();

	for (int i=0; i<TEXTMESSAGES_SIZE; i++)
	{
		textMessagesBuffer[i]=0;
	}

	textMessagesBuffer[0]='\n';
}

void MessagesView::tearDownScreen()
{
	MessagesViewBase::tearDownScreen();
}

void MessagesView::handleTickEvent()
{
	static int counter=0;
	Unicode::UnicodeChar localStr[40];
	uint8_t utf8str[]="lorem_ipsum";

	counter++;
	if (counter>100)
	{
		counter=0;

		if (Unicode::strlen(textMessagesBuffer)<TEXTMESSAGES_SIZE-20)
		{
			Unicode::fromUTF8(utf8str, localStr, 40);
			Unicode::snprintf(textMessagesBuffer, TEXTMESSAGES_SIZE,
					"%s\n%s",localStr, textMessagesBuffer);

			textMessages.invalidate();
		}
	}
}

void MessagesView::buttonMessagesClicked()
{

}

void MessagesView::buttonWipeClicked()
{
	textMessages.invalidate();

	for (int i=0; i<TEXTMESSAGES_SIZE; i++)
	{
		textMessagesBuffer[i]=0;
	}

	textMessagesBuffer[0]='\n';
}
