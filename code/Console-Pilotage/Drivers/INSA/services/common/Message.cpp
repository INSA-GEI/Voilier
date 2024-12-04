/*
 * Message.cpp
 *
 *  Created on: 17 avr. 2020
 *      Author: dimercur
 */

#include <common/Message.h>

/**
 * Create a new, empty message
 */
Message::Message() {
    this->header = string("");
}

/**
 * Destroy message
 */
Message::~Message() {
}

/**
 * Translate content of message into a string that can be displayed
 * @return A string describing message contents
 */
string Message::ToString() {
    if (CheckHeader(this->header))
        return "Id: \"" + this->header + "\"";
    else
        return "Invalid message";
}

/**
 * Allocate a new mesage and copy contents of current message
 * @return A message, copy of current
 */
Message* Message::Copy() {
    Message *msg = new Message();

    return msg;
}

/**
 * Get message ID
 * @return Current message ID
 */
bool Message::CheckHeader(string header) {
    if ((header != "")) {
        return false;
    } else return true;
}


