/*
 * uart.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef INSA_UART_H_
#define INSA_UART_H_

#include "stm32f7xx_hal.h"
#include "driver.h"
#include <functional>
#include <vector>

#define RXBUFFERSIZE 100
#define TXBUFFERSIZE 100

typedef std::function<void(std::vector<uint8_t> data)> RXCallee;
typedef std::function<void(int errorType)> ErrorCallee;

#define UART_IT_SIGNAL_DMA_TX 		1
#define UART_IT_SIGNAL_DMA_RX 		2
#define UART_IT_SIGNAL_ERROR 		3

#define UART_STATUS_SUCCESS 		0
#define UART_STATUS_INIT_FAILED 	1

class Uart : public Driver {
public:
	Uart(USART_TypeDef *usart);
	virtual ~Uart();
	virtual void interruptHandler(int signal);

	void addReceptionCallback(RXCallee callee) { this->rxCallee = callee; }
	void addErrorCallback(ErrorCallee callee) { this->errorCallee = callee;	}
	int getStatus() { return lastStatus; }

private:
	int lastStatus = UART_STATUS_SUCCESS;

	UART_HandleTypeDef UartHandle;
	/* Buffer used for transmission */
	uint8_t aTxBuffer[TXBUFFERSIZE];
	/* Buffer used for reception */
	uint8_t aRxBuffer[RXBUFFERSIZE];

	RXCallee rxCallee = nullptr;
	ErrorCallee errorCallee = nullptr;
};

#endif /* INSA_UART_H_ */
