/*
 * Xbee.cpp
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#include "xbee.h"

static USART_TypeDef* xbeeUsart;
int xbeeDesAddress;
int xbeeOwnAddress;
int xbeeLastRssi;
int xbeeLastError;
void XbeeUARTRxCallback( int length, uint8_t *data);

void Error_Handler(void);

int XbeeInit(USART_TypeDef* usart) {
	// Init corresponding UART for Xbee
	xbeeUsart=usart;

	if (UartInit(xbeeUsart)!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		return xbeeLastError;
	}

	UartAddReceptionCallback(XbeeUARTRxCallback);

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

int XbeeDeInit() {
	// TODO Auto-generated destructor stub
	if (UartDeInit(xbeeUsart)!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		return xbeeLastError;
	}

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

int XbeeSetup(int ownAddress) {
	xbeeOwnAddress = ownAddress;

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

int XbeeGetLastRSSI() {

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

int XbeeGetLastStatus() {
	return xbeeLastError;
}

void XbeeSetDestinationAddress(int desAddress) {

}

int XbeeSendData(uint8_t *data, int length) {

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

int XbeeGetReceivedLength() {
	return 0;
}

void XbeeSetEndingChar(uint8_t endingChar) {

}

int XbeeReadData(uint8_t *data, int length) {

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

void XbeeUARTRxCallback(int length, uint8_t *data) {

}
