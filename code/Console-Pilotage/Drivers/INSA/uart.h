/*
 * uart.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef INSA_UART_H_
#define INSA_UART_H_

#include "stm32f7xx_hal.h"

#define RXBUFFERSIZE 100
#define TXBUFFERSIZE 100

#define UART_IT_SIGNAL_DMA_TX 		1
#define UART_IT_SIGNAL_DMA_RX 		2
#define UART_IT_SIGNAL_ERROR 		3

#define UART_STATUS_SUCCESS 		0
#define UART_STATUS_INIT_FAILED 	1

typedef void (*UARTReceptionCallback) (int length, uint8_t *data);
typedef void (*UARTErrorCallback) (int errorType);

int UartInit(USART_TypeDef *usart);
int UartDeInit(USART_TypeDef *usart);

void UartAddReceptionCallback(UARTReceptionCallback callee);
void UartAddErrorCallback(UARTErrorCallback callee);

int UartGetStatus(void);
int UartSendData(uint8_t* data, int length);
void UartStartRX(void);

int UartGetReceivedLength();
void UartSetEndingChar(uint8_t endingChar);

int UARTReadData(uint8_t *data, int *length);
#endif /* INSA_UART_H_ */
