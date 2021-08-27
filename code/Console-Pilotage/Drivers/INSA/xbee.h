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

int XbeeSetup(int ownAddress, int desAddress);
char XbeeIsConfigured();

int XbeeGetLastRSSI();
int XbeeGetLastStatus();

void XbeeStartRx(void);
void XbeeStopRx(void);
void XbeeFlush(void);

void XbeeSetDestinationAddress(int desAddress);
void XbeeSetOwnAddress(int ownAddress);
int XbeeWriteData(uint8_t *data, int length);

int XbeeGetReceivedLength();
void XbeeSetEndingChar(uint8_t endingChar);

int XbeeReadData(uint8_t *data);
void XbeeAddReceptionCallback(XBEEDataReceivedCallback callee);

void XbeeSendRotation(void);
void XbeeSetRotation(int rot);
#endif /* XBEE_H_ */
