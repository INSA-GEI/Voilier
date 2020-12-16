/*
 * Xbee.cpp
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#include "xbee.h"
#include "string.h"
#include "stdio.h"

static USART_TypeDef* xbeeUsart;
int xbeeDesAddress;
int xbeeOwnAddress;
int xbeeLastRssi;
int xbeeLastError;

uint8_t xbeeReceivedFrame[100];
uint8_t xbeeEndingCharFlag;
uint8_t xbeeReceivedLength;
uint8_t xbeeEndingChar;

void XbeeUARTRxCallback(uint8_t data);
void Error_Handler(void);
void XbeeFlush(void);

int XbeeInit(USART_TypeDef* usart) {
	// Init corresponding UART for Xbee
	xbeeUsart=usart;

	if (UartInit(xbeeUsart)!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		return xbeeLastError;
	}

	UartAddReceptionCallback(XbeeUARTRxCallback);

	xbeeEndingCharFlag=0;
	xbeeReceivedLength=0;
	xbeeEndingChar=0;

	for (int i=0; i<100; i++) {
		xbeeReceivedFrame[i]=0;
	}

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

int XbeeSetup(int ownAddress,int desAddress) {
	char strbuf[20];

	xbeeOwnAddress = ownAddress;
	xbeeDesAddress = desAddress;

	XbeeSetEndingChar(0x0D);

	/* Passe en mode configuration */
	if (UartWriteData((uint8_t *)"+++", strlen("+++"))!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	HAL_Delay(1500); // attente de 1.5 s

	if (xbeeEndingCharFlag==0) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	if (strstr((char *)xbeeReceivedFrame, "OK") == NULL) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	XbeeFlush();

	/* Defini l'adresse destination */
	sprintf(strbuf, "ATDL %04X\r",xbeeDesAddress);
	if (UartWriteData((uint8_t *)strbuf, strlen(strbuf))!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	HAL_Delay(100); // attente de 0.1 s

	if (xbeeEndingCharFlag==0) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	if (strstr((char *)xbeeReceivedFrame, "OK") == NULL) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	XbeeFlush();

	/* Defini l'adresse source */
	sprintf(strbuf, "ATMY %04X\r",xbeeOwnAddress);
	if (UartWriteData((uint8_t *)strbuf, strlen(strbuf))!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	HAL_Delay(100); // attente de 0.1 s

	if (xbeeEndingCharFlag==0) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	if (strstr((char *)xbeeReceivedFrame, "OK") == NULL) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	XbeeFlush();

	/* Termine le mode configuration */
	if (UartWriteData((uint8_t *)"ATCN\n", strlen("ATCN\n"))!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	HAL_Delay(100); // attente de 0.1 s

	if (xbeeEndingCharFlag==0) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	if (strstr((char *)xbeeReceivedFrame, "OK") == NULL) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		Error_Handler();
	}

	XbeeFlush();

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

void XbeeFlush(void) {
	xbeeReceivedFrame[0]=0;
	xbeeReceivedLength=0;
	xbeeEndingCharFlag=0;
}

int XbeeGetLastRSSI() {
	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastRssi;
}

int XbeeGetLastStatus() {
	return xbeeLastError;
}

void XbeeSetDestinationAddress(int desAddress) {
	xbeeDesAddress = desAddress;

	xbeeLastError = XBEE_STATUS_SUCCESS;
}

void XbeeSetOwnAddress(int ownAddress) {
	xbeeOwnAddress = ownAddress;

	xbeeLastError = XBEE_STATUS_SUCCESS;
}

int XbeeSendData(uint8_t *data, int length) {
	xbeeLastError = XBEE_STATUS_SUCCESS;

	if (UartWriteData(data, length)!=UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_SEND_ERR;
	}

	return xbeeLastError;
}

void XbeeSetEndingChar(uint8_t endingChar) {
	xbeeEndingChar = endingChar;
	xbeeLastError = XBEE_STATUS_SUCCESS;
}

int XbeeGetReceivedLength() {
	return (int)xbeeReceivedLength;
}

int XbeeReadData(uint8_t *data) {
	int length = (int)xbeeReceivedLength;
	xbeeLastError = XBEE_STATUS_SUCCESS;

	for (int i=0; i<length; i++) {
		data[i]=xbeeReceivedFrame[i];
	}

	data[length]=0;

	xbeeReceivedFrame[0]=0;
	xbeeReceivedLength=0;
	xbeeEndingCharFlag=0;
	return length;
}

void XbeeUARTRxCallback(uint8_t data) {
	/* La chaine recu contient le caractere de fin de chaine (CR, LF ou autre), a retirer */

	xbeeReceivedFrame[xbeeReceivedLength]=data;
	xbeeReceivedFrame[(xbeeReceivedLength++)]=0;

	if (data == xbeeEndingChar) xbeeEndingCharFlag=1;
}
