/*
 * Xbee.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef XBEE_H_
#define XBEE_H_

#include "uart.h"

typedef void (*XBEEDataReceivedCallback) (int length, uint8_t *data);

	void XbeeInit(USART_TypeDef* uart);
	void XbeeDeInit();

	int Xbeesetup(int ownAddress);
	int XbeeGetLastRSSI();
	int XbeeGetLastStatus();

	void XbeeSetDestinationAddress(int desAddress);
	int XbeeSendData(uint8_t *data, int length);

	int XbeeGetReceivedLength();
	void XbeeSetEndingChar(uint8_t endingChar);

	int XbeeReadData(uint8_t *data, int length);
	void XbeeAddReceptionCallback(XBEEDataReceivedCallback callee);

#endif /* XBEE_H_ */
