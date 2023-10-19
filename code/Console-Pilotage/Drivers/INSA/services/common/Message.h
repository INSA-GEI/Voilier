/*
 * Message.h
 *
 *  Created on: 17 avr. 2020
 *      Author: dimercur
 */

#ifndef INSA_SERVICES_MESSAGE_H_
#define INSA_SERVICES_MESSAGE_H_

#include <string>

using namespace std;

/**
 * Base class for messaging
 *
 * @brief Base class for messaging
 *
 */
class Message {
public:
	/**
	 * Create a new, empty message
	 */
	Message();

	/**
	 * Destroy message
	 */
	virtual ~Message();

	/**
	 * Translate content of message into a string that can be displayed
	 * @return A string describing message contents
	 */
	virtual string ToString();

	/**
	 * Allocate a new message and copy contents of current message
	 * @return A message, copy of current
	 */
	virtual Message* Copy();

	/**
	 * Get message ID
	 * @return Current message ID
	 */
	string GetHeader() {
		return header;
	}

	/**
	 * Set message ID
	 * @param id Message ID
	 */
	virtual void SetHeader(string header) {
	}

	/**
	 * Comparison operator
	 * @param msg Message to be compared
	 * @return true if message are equal, false otherwise
	 */
	bool operator==(const Message& msg) {
		return (header == msg.header);
	}

	/**
	 * Difference operator
	 * @param msg Message to be compared
	 * @return true if message are different, false otherwise
	 */
	bool operator!=(const Message& msg) {
		return !(header == msg.header);
	}

protected:
	/**
	 * Message identifier (@see MessageID)
	 */
	string header;

	/**
	 * Verify if message ID is compatible with current message type
	 * @param id Message ID
	 * @return true, if message ID is acceptable, false otherwise
	 */
	virtual bool CheckHeader(string header);
};

#endif /* INSA_SERVICES_MESSAGE_H_ */
