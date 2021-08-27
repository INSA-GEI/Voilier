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

#define XBEE_RECEIVED_FRAME_LENGTH 100
uint8_t xbeeReceivedFrame[XBEE_RECEIVED_FRAME_LENGTH];
uint8_t xbeeEndingCharFlag;
uint8_t xbeeReceivedLength;
uint8_t xbeeEndingChar;

void XbeeUARTRxCallback(uint8_t data);
void XbeeFlush(void);

int rotation=0;
static char isConfigured=0;

int XbeeInit(USART_TypeDef* usart) {
	// Init corresponding UART for Xbee
	xbeeUsart=usart;

	if (UartInit(xbeeUsart)!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	UartAddReceptionCallback(XbeeUARTRxCallback);

	xbeeEndingCharFlag=0;
	xbeeReceivedLength=0;
	xbeeEndingChar=0;

	for (int i=0; i<XBEE_RECEIVED_FRAME_LENGTH; i++) {
		xbeeReceivedFrame[i]=0;
	}

	//UartStartRX();
	isConfigured=0;

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

int XbeeDeInit() {
	UartStopRX();
	isConfigured=0;

	// TODO Auto-generated destructor stub
	if (UartDeInit(xbeeUsart)!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

int XbeeSetup(int ownAddress,int desAddress) {
	char strbuf[20];
	isConfigured=0;

	xbeeOwnAddress = ownAddress;
	xbeeDesAddress = desAddress;

	XbeeFlush();
	XbeeSetEndingChar(0x0D);

	/* Passe en mode configuration */
	if (UartWriteData((uint8_t *)"+++", strlen("+++"))!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	HAL_Delay(1500); // attente de 1.5 s

	if (xbeeEndingCharFlag==0) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	if (strstr((char *)xbeeReceivedFrame, "OK") == NULL) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	XbeeFlush();

	/* Defini l'adresse destination */
	sprintf(strbuf, "ATDL %04X\r",xbeeDesAddress);
	if (UartWriteData((uint8_t *)strbuf, strlen(strbuf))!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	HAL_Delay(100); // attente de 0.1 s

	if (xbeeEndingCharFlag==0) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	if (strstr((char *)xbeeReceivedFrame, "OK") == NULL) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	XbeeFlush();

	/* Defini l'adresse source */
	sprintf(strbuf, "ATMY %04X\r",xbeeOwnAddress);
	if (UartWriteData((uint8_t *)strbuf, strlen(strbuf))!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	HAL_Delay(100); // attente de 0.1 s

	if (xbeeEndingCharFlag==0) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	if (strstr((char *)xbeeReceivedFrame, "OK") == NULL) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	XbeeFlush();

	/* Termine le mode configuration */
	if (UartWriteData((uint8_t *)"ATCN\r", strlen("ATCN\r"))!= UART_STATUS_SUCCESS) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	HAL_Delay(100); // attente de 0.1 s

	if (xbeeEndingCharFlag==0) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	if (strstr((char *)xbeeReceivedFrame, "OK") == NULL) {
		xbeeLastError = XBEE_STATUS_CONFIG_ERR;
		assert_failed((uint8_t *)__FILE__,__LINE__);

		return xbeeLastError;
	}

	XbeeFlush();

	isConfigured=1;
	xbeeLastError = XBEE_STATUS_SUCCESS;
	return xbeeLastError;
}

char XbeeIsConfigured()
{
	return isConfigured;
}

void XbeeStartRx(void) {
	UartStartRX();
}

void XbeeStopRx(void) {
	UartStopRX();
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

int XbeeWriteData(uint8_t *data, int length) {
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

	xbeeReceivedFrame[xbeeReceivedLength++]=data;
	if (xbeeReceivedLength>=XBEE_RECEIVED_FRAME_LENGTH) xbeeReceivedLength = XBEE_RECEIVED_FRAME_LENGTH-1;

	xbeeReceivedFrame[xbeeReceivedLength]=0;

	if (data == xbeeEndingChar) xbeeEndingCharFlag=1;
}

void XbeeSendRotation(void)
{
	printf ("%d\n", rotation);
	signed char rot = (signed char)rotation;
	XbeeWriteData((uint8_t*)&rot, 1);
}

void XbeeSetRotation(int rot)
{
	rotation=rot;
}
