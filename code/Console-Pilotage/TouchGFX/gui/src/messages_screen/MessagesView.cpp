#include <gui/messages_screen/MessagesView.hpp>

extern "C" {
#include "xbee.h"
void assert_failed(uint8_t *file, uint32_t line);
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

MessagesView::MessagesView()
{

}

void MessagesView::setupScreen()
{
	MessagesViewBase::setupScreen();

	for (int i=0; i<TEXTMESSAGES_SIZE; i++)
	{
		textMessagesBuffer[i]=0;
		textBuffer[i]=0;
	}

	textMessagesBuffer[0]='\n';

	XbeeFlush();
}

void MessagesView::tearDownScreen()
{
	MessagesViewBase::tearDownScreen();
}

void MessagesView::handleTickEvent()
{
	static int counter=0;

	counter++;
	if (counter>10)
	{
		counter=0;

		if (XbeeGetReceivedLength()>0) {
			int length = XbeeGetReceivedLength();
			uint8_t str[length+5];

			if (XbeeReadData(str)!= XBEE_STATUS_SUCCESS) {
				assert_failed((uint8_t *) __FILE__, __LINE__);
			}

			for (int i=0; i<length; i++) {
				if ((str[i]=='\r') || (str[i]=='\n')) str[i]='\n';
				else if (!isprint(str[i])) str[i]=' ';
			}

			str[length]=0;

			if (Unicode::strlen(textMessagesBuffer)<TEXTMESSAGES_SIZE-length)
			{
				strcat((char *)textBuffer, (char *) str);
				Unicode::fromUTF8(textBuffer, textMessagesBuffer, TEXTMESSAGES_SIZE);
				//Unicode::snprintf(textMessagesBuffer, TEXTMESSAGES_SIZE,
				//		"%s%s",localStr, textMessagesBuffer);

				textMessages.invalidate();
			}
		}
	}
}

void MessagesView::buttonMessagesClicked()
{

}

void MessagesView::buttonWipeClicked()
{
	for (int i=0; i<TEXTMESSAGES_SIZE; i++)
	{
		textMessagesBuffer[i]=0;
		textBuffer[i]=0;
	}

	textMessagesBuffer[0]='\n';

	textMessages.invalidate();
}
