/*
 * uart.cpp
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#include <Uart.h>
#include "stm32f7xx_it_wrapper.h"

Uart::Uart(char uartNbr) {
	// TODO Auto-generated constructor stub
	lastStatus = Status_Success;

	switch (uartNbr)
	{
	case 6:
		uartHandle.Instance		= USART6;
		break;
	default:
		// Only Uart6 is implemented yet
		while (1);
	}

	uartHandle.Init.BaudRate   = 9600;
	uartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	uartHandle.Init.StopBits   = UART_STOPBITS_1;
	uartHandle.Init.Parity     = UART_PARITY_NONE;
	uartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	uartHandle.Init.Mode       = UART_MODE_TX_RX;
	if(HAL_UART_DeInit(&uartHandle) != HAL_OK)
	{
		lastStatus = Status_Failed;
		return;
	}

	if(HAL_UART_Init(&uartHandle) != HAL_OK)
	{
		lastStatus = Status_Failed;
		return;
	}

	if (uartHandle.Instance	== USART6)
	{
		static DMA_HandleTypeDef hdma_tx;
		static DMA_HandleTypeDef hdma_rx;

		GPIO_InitTypeDef  GPIO_InitStruct;

		/*##-1- Enable peripherals and GPIO Clocks #################################*/
		/* Enable GPIO TX/RX clock */
		__GPIOC_CLK_ENABLE();
		__GPIOC_CLK_ENABLE();

		/* Enable USARTx clock */
		__USART6_CLK_ENABLE();

		/* Enable DMA clock */
		//__HAL_RCC_DMA2_CLK_ENABLE();

		WRAPPER_InitUsart6(*this);

		/*##-2- Configure peripheral GPIO ##########################################*/
		/* UART TX GPIO pin configuration  */
		GPIO_InitStruct.Pin       =  GPIO_PIN_6;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_PULLUP;
		GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_USART6;

		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		/* UART RX GPIO pin configuration  */
		GPIO_InitStruct.Pin = GPIO_PIN_7;
		GPIO_InitStruct.Alternate = GPIO_AF8_USART6;

		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		/*##-3- Configure the DMA ##################################################*/
		/* Configure the DMA handler for Transmission process */
		hdma_tx.Instance                 = DMA2_Stream6;
		hdma_tx.Init.Channel             = DMA_CHANNEL_5;
		hdma_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
		hdma_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
		hdma_tx.Init.MemInc              = DMA_MINC_ENABLE;
		hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
		hdma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
		hdma_tx.Init.Mode                = DMA_NORMAL;
		hdma_tx.Init.Priority            = DMA_PRIORITY_LOW;

		HAL_DMA_Init(&hdma_tx);

		/* Associate the initialized DMA handle to the UART handle */
		__HAL_LINKDMA(&uartHandle, hdmatx, hdma_tx);

		/* Configure the DMA handler for reception process */
		hdma_rx.Instance                 = DMA2_Stream1;
		hdma_rx.Init.Channel             = DMA_CHANNEL_5;
		hdma_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
		hdma_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
		hdma_rx.Init.MemInc              = DMA_MINC_ENABLE;
		hdma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
		hdma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
		hdma_rx.Init.Mode                = DMA_NORMAL;
		hdma_rx.Init.Priority            = DMA_PRIORITY_HIGH;

		HAL_DMA_Init(&hdma_rx);

		/* Associate the initialized DMA handle to the the UART handle */
		__HAL_LINKDMA(&uartHandle, hdmarx, hdma_rx);

		/*##-4- Configure the NVIC for DMA #########################################*/
		/* NVIC configuration for DMA transfer complete interrupt (USART6_TX) */
		HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 0, 1);
		HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

		/* NVIC configuration for DMA transfer complete interrupt (USART6_RX) */
		HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

		/* NVIC for USART, to catch the TX complete */
		HAL_NVIC_SetPriority(USART6_IRQn, 0, 1);
		HAL_NVIC_EnableIRQ(USART6_IRQn);
	}
}

Uart::~Uart() {
	// TODO Auto-generated destructor stub
	/*##-1- Reset peripherals ##################################################*/
	if (uartHandle.Instance	== USART6) {
		__USART6_FORCE_RESET();
		__USART6_RELEASE_RESET();

		/*##-2- Disable peripherals and GPIO Clocks #################################*/
		/* Configure USARTx Tx as alternate function  */
		HAL_GPIO_DeInit(GPIOC,  GPIO_PIN_6);
		/* Configure USARTx Rx as alternate function  */
		HAL_GPIO_DeInit(GPIOC, GPIO_PIN_7);

		/*##-3- Disable the DMA #####################################################*/
		/* De-Initialize the DMA channel associated to reception process */
		if(uartHandle.hdmarx != 0)
		{
			HAL_DMA_DeInit(uartHandle.hdmarx);
		}
		/* De-Initialize the DMA channel associated to transmission process */
		if(uartHandle.hdmatx != 0)
		{
			HAL_DMA_DeInit(uartHandle.hdmarx);
		}

		/*##-4- Disable the NVIC for DMA ###########################################*/
		HAL_NVIC_DisableIRQ(DMA2_Stream6_IRQn);
		HAL_NVIC_DisableIRQ(DMA2_Stream1_IRQn);
	}
}

UART_HandleTypeDef* Uart::GetHandle() {
	return &this->uartHandle;
}

void Uart::ProcessHwEvent(UART_HwEventID eventId) {

}
