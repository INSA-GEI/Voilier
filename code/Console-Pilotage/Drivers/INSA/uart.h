/*
 * uart.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef INSA_UART_H_
#define INSA_UART_H_

#include "stm32f7xx_hal.h"
#include "BaseObject.h"
#include "driver.h"
#include <functional>
#include <vector>
#include <string>

#define RXBUFFERSIZE 100
#define TXBUFFERSIZE 100

typedef std::function<void(BaseObject& obj, std::vector<uint8_t> &data)> UARTReceptionCallback;
typedef std::function<void(BaseObject& obj, int errorType)> UARTErrorCallback;

#define UART_IT_SIGNAL_DMA_TX 		1
#define UART_IT_SIGNAL_DMA_RX 		2
#define UART_IT_SIGNAL_ERROR 		3

#define UART_STATUS_SUCCESS 		0
#define UART_STATUS_INIT_FAILED 	1

class Uart : public Driver, public BaseObject {
public:
	Uart(USART_TypeDef *usart);
	virtual ~Uart();
	virtual void interruptHandler(int signal);

	void addReceptionCallback(BaseObject& obj, UARTReceptionCallback callee) { this->RXCalleeObj = &obj; this->rxCallee = callee; }
	void addErrorCallback(BaseObject& obj, UARTErrorCallback callee) { this->ErrorCalleeObj = &obj; this->errorCallee = callee;	}
	int getStatus() { return lastStatus; }

	int sendData(std::vector<uint8_t> data);
	int sendData(std::string str);
	int sendData(uint8_t* data, int length);

	int getReceivedLength();
	void setEndingChars(std::vector<uint8_t> endingChars) {this->endingChars = endingChars; }

	int readData(std::vector<uint8_t> &data);
	int readData(std::string &str);
	int readData(uint8_t &data, int length);

private:

	int lastStatus = UART_STATUS_SUCCESS;

	UART_HandleTypeDef UartHandle;
	/* Buffer used for transmission */
	uint8_t aTxBuffer[TXBUFFERSIZE];
	/* Buffer used for reception */
	uint8_t aRxBuffer[RXBUFFERSIZE];

	BaseObject* RXCalleeObj = nullptr;
	BaseObject* ErrorCalleeObj = nullptr;
	UARTReceptionCallback rxCallee = nullptr;
	UARTErrorCallback errorCallee = nullptr;

	std::vector<uint8_t> endingChars;
};

#endif /* INSA_UART_H_ */
