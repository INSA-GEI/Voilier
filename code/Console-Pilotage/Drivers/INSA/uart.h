/*
 * uart.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef INSA_UART_H_
#define INSA_UART_H_

#include "stm32f7xx_hal.h"

#define UART_RX_BUFFERSIZE 100
#define UART_TX_BUFFERSIZE 100

#define UART_IT_SIGNAL_DMA_TX 		1
#define UART_IT_SIGNAL_DMA_RX 		2
#define UART_IT_SIGNAL_ERROR 		3

#define UART_STATUS_SUCCESS 		0
#define UART_STATUS_INIT_FAILED 	1
#define UART_STATUS_READ_ERR		2
#define UART_STATUS_WRITE_ERR		2

typedef void (*UARTReceptionCallback) (uint8_t data);
typedef void (*UARTErrorCallback) (int errorType);

int UartInit(USART_TypeDef *usart);
int UartDeInit(USART_TypeDef *usart);

void UartAddReceptionCallback(UARTReceptionCallback callee);
void UartAddErrorCallback(UARTErrorCallback callee);

int UartGetLastStatus(void);

void UartStartRX(void);
void UartStopRX(void);
int UartGetReceivedLength();

int UartWriteData(uint8_t* data, int length);
int UARTReadData(uint8_t *data);

#endif /* INSA_UART_H_ */
