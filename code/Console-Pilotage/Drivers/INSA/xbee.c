/*
 * Xbee.cpp
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#include "xbee.h"

static USART_TypeDef* huartHandler;
int desAddress;
int ownAddress;
int lastRssi;
int lastError;
void XbeeUARTRxCallback( int length, uint8_t *data);

void XbeeInit(USART_TypeDef* handler) {
	// TODO Auto-generated constructor stub
	huartHandler = handler;

	UartAddReceptionCallback(XbeeUARTRxCallback);
}

void XbeeDeInit() {
	// TODO Auto-generated destructor stub
}


void XbeeUARTRxCallback(int length, uint8_t *data) {
	//	Xbee& baseClass = (Xbee&)obj;
	//
	//	baseClass->receptionBuffer.insert(baseClass->receptionBuffer.begin(), data.begin(), data.end());
}
