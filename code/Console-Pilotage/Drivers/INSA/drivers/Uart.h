/*
 * uart.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef INSA_UART_H_
#define INSA_UART_H_

#include "stm32f7xx_hal.h"
#include "FreeRTOS.h"
#include "queue.h"

#include "common/Service.h"

#define RXBUFFERSIZE 100
#define TXBUFFERSIZE 100

typedef enum {
	Data_Received=0,
	Data_Sent,
	Error
} UART_HwEventID;

typedef enum {
	Status_Failed=0,
	Status_Success
} UART_Status;

class Uart : public Service {
public:
	Uart(char uartNbr);
	virtual ~Uart();

	UART_HandleTypeDef* GetHandle();

	void ProcessHwEvent(UART_HwEventID eventId);
private:
	UART_HandleTypeDef uartHandle;

	/* Buffer used for transmission */
	uint8_t aTxBuffer[TXBUFFERSIZE];
	/* Buffer used for reception */
	uint8_t aRxBuffer[RXBUFFERSIZE];

	UART_Status lastStatus = Status_Success;

	virtual int ProcessMsg(Message *msg);
};

#endif /* INSA_UART_H_ */
