/*
 * Xbee.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef XBEE_H_
#define XBEE_H_

#include <common/Service.h>
#include <Uart.h>
#include <common/Message.h>
#include <vector>

class XbeeMessageSent : public Message {
public:
	int destAddress;
};

class XbeeMessageReceived : public Message {
public:
	int RSSI;
};

class XbeeMessageacknowledge : public Message {
public:
	bool ack;
};

class XbeeSrv : public Service {
public:
	XbeeSrv(Uart &uart);
	virtual ~XbeeSrv();

	int Setup(int ownAddress);
	int GetLastRSSI();
	int GetLastStatus();
	void ChangeOwnAddress(int ownAddress);
	void SetDefaultDestinationAddress(int desAddress);
	void SetEndingChar(uint8_t endingChar);

	/* Envoi des données via PostMsg */

	/* Reception via registerService et PostMsg sur le service enregistré */
private:
	Uart uartRef;

	int defaultAddress;
	int lastRSSI;
	int lastStatus;

	int ownAddress;
};

#endif /* XBEE_H_ */
