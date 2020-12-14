/*
 * Xbee.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef XBEE_H_
#define XBEE_H_

#include "uart.h"

#define XBEE_STATUS_SUCCESS 	0
#define XBEE_STATUS_CONFIG_ERR 	1
#define XBEE_STATUS_SEND_ERR 	2

typedef void (*XBEEDataReceivedCallback) (int length, uint8_t *data);

int XbeeInit(USART_TypeDef* uart);
int XbeeDeInit();

int XbeeSetup(int ownAddress);
int XbeeGetLastRSSI();
int XbeeGetLastStatus();

void XbeeSetDestinationAddress(int desAddress);
int XbeeSendData(uint8_t *data, int length);

int XbeeGetReceivedLength();
void XbeeSetEndingChar(uint8_t endingChar);

int XbeeReadData(uint8_t *data);
void XbeeAddReceptionCallback(XBEEDataReceivedCallback callee);

#endif /* XBEE_H_ */
