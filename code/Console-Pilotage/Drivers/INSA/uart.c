/*
 * uart.c
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

/*
 * Driver de liaison serie
 *
 * Principe de fonctionnement:
 *      - Si une fonction callback est associée à la reception de donnée (uartDataReceivedCbk), les octets recus sont envoyés
 *        directement à la fonction callback, sans etre stocké dans le buffer de reception: la quantité de données presentes
 *        dans le buffer est toujours egale à zero
 *
 *      - Si aucune fonction callback n'est associée à la reception de donnée, les octets recus sont stockés dans le buffer
 *        de reception et la quantité de donnée recu augmentées: les données stockées dans le buffer sont recuperé avec la
 *        fonction UARTReadData
 */
#include "uart.h"

int uartLastStatus = UART_STATUS_SUCCESS;

UART_HandleTypeDef huart6;
/* Buffer used for transmission */
uint8_t uartTxBuffer[UART_TX_BUFFERSIZE];
/* Buffer used for reception */
uint8_t uartRxBuffer[UART_RX_BUFFERSIZE];
uint16_t uartRxDataCounter;

UARTReceptionCallback uartDataReceivedCbk=NULL;
UARTErrorCallback uartDataErrorCbk=NULL;

void Error_Handler(void);

int UartInit(USART_TypeDef *usart) {
	// TODO Auto-generated constructor stub

	huart6.Instance        = usart;

	huart6.Init.BaudRate   = 9600;
	huart6.Init.WordLength = UART_WORDLENGTH_8B;
	huart6.Init.StopBits   = UART_STOPBITS_1;
	huart6.Init.Parity     = UART_PARITY_NONE;
	huart6.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	huart6.Init.Mode       = UART_MODE_TX_RX;
	if(HAL_UART_DeInit(&huart6) != HAL_OK)
	{
		uartLastStatus = UART_STATUS_INIT_FAILED;
		return uartLastStatus;
	}

	if(HAL_UART_Init(&huart6) != HAL_OK)
	{
		uartLastStatus = UART_STATUS_INIT_FAILED;
		return uartLastStatus;
	}

	if (usart == USART6)
	{
		static DMA_HandleTypeDef hdma_tx;
		//static DMA_HandleTypeDef hdma_rx;

		GPIO_InitTypeDef  GPIO_InitStruct;

		/*##-1- Enable peripherals and GPIO Clocks #################################*/
		/* Enable GPIO TX/RX clock */
		__GPIOC_CLK_ENABLE();
		__GPIOC_CLK_ENABLE();

		/* Enable USARTx clock */
		__USART6_CLK_ENABLE();

		/* Enable DMA clock */
		__HAL_RCC_DMA2_CLK_ENABLE();

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
		__HAL_LINKDMA(&huart6, hdmatx, hdma_tx);

		//		/* Configure the DMA handler for reception process */
		//		hdma_rx.Instance                 = DMA2_Stream1;
		//		hdma_rx.Init.Channel             = DMA_CHANNEL_5;
		//		hdma_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
		//		hdma_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
		//		hdma_rx.Init.MemInc              = DMA_MINC_ENABLE;
		//		hdma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
		//		hdma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
		//		hdma_rx.Init.Mode                = DMA_NORMAL;
		//		hdma_rx.Init.Priority            = DMA_PRIORITY_HIGH;
		//
		//		HAL_DMA_Init(&hdma_rx);
		//
		//		/* Associate the initialized DMA handle to the the UART handle */
		//		__HAL_LINKDMA(&huart6, hdmarx, hdma_rx);

		/*##-4- Configure the NVIC for DMA #########################################*/
		/* NVIC configuration for DMA transfer complete interrupt (USART6_TX) */
		HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 0, 1);
		HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

		//		/* NVIC configuration for DMA transfer complete interrupt (USART6_RX) */
		//		HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
		//		HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

		/* NVIC for USART, to catch the TX complete and RXNIE */
		HAL_NVIC_SetPriority(USART6_IRQn, 0, 1);
		HAL_NVIC_EnableIRQ(USART6_IRQn);
	}

	/* Initialisation diverses */
	uartRxDataCounter=0;

	uartLastStatus = UART_STATUS_SUCCESS;
	return uartLastStatus;
}

int UartDeInit(USART_TypeDef *usart) {
	// TODO Auto-generated destructor stub
	/*##-1- Reset peripherals ##################################################*/
	__USART6_FORCE_RESET();
	__USART6_RELEASE_RESET();

	/*##-2- Disable peripherals and GPIO Clocks #################################*/
	/* Configure USARTx Tx as alternate function  */
	HAL_GPIO_DeInit(GPIOC,  GPIO_PIN_6);
	/* Configure USARTx Rx as alternate function  */
	HAL_GPIO_DeInit(GPIOC, GPIO_PIN_7);

	/*##-3- Disable the DMA #####################################################*/
	/* De-Initialize the DMA channel associated to reception process */
	if(huart6.hdmarx != 0)
	{
		HAL_DMA_DeInit(huart6.hdmarx);
	}
	/* De-Initialize the DMA channel associated to transmission process */
	if(huart6.hdmatx != 0)
	{
		HAL_DMA_DeInit(huart6.hdmarx);
	}

	/*##-4- Disable the NVIC for DMA ###########################################*/
	HAL_NVIC_DisableIRQ(DMA2_Stream6_IRQn);
	HAL_NVIC_DisableIRQ(DMA2_Stream1_IRQn);
	HAL_NVIC_DisableIRQ(USART6_IRQn);

	uartDataReceivedCbk=NULL;
	uartDataErrorCbk=NULL;

	uartLastStatus = UART_STATUS_SUCCESS;
	return uartLastStatus;
}

void UartAddReceptionCallback(UARTReceptionCallback callee) {
	uartDataReceivedCbk=callee;
}

void UartAddErrorCallback(UARTErrorCallback callee) {
	uartDataErrorCbk=callee;
}

int UartGetLastStatus(void) {
	return ((int)uartLastStatus);
}

void UartStartRX(void) {
	if(HAL_UART_Receive_IT(&huart6, (uint8_t *)uartRxBuffer, 1) != HAL_OK)
	{
	   Error_Handler();
	}
}

void UartStopRX(void) {
	if(HAL_UART_AbortReceive(&huart6) != HAL_OK)
	{
	   Error_Handler();
	}
}

int UartWriteData(uint8_t* data, int length) {
	int status;

	uartLastStatus = UART_STATUS_SUCCESS;

	for (int i; i< length; i++) {
		uartTxBuffer[i] = data[i];
	}

	status=HAL_UART_Transmit_DMA(&huart6, (uint8_t*)uartTxBuffer, length);

	if (status!=HAL_OK)
	{
		uartLastStatus = UART_STATUS_WRITE_ERR;
		Error_Handler();
	}

	return uartLastStatus;
}

int UartGetReceivedLength() {
	return ((int)uartRxDataCounter);
}

int UARTReadData(uint8_t *data) {
	int length = (int)uartRxDataCounter;

	if (data==NULL) {
		uartLastStatus=UART_STATUS_READ_ERR;
		Error_Handler();
	}

	__disable_irq();
	for (int i=0; i<uartRxDataCounter; i++) {
		data[i]=uartRxBuffer[i];
	}

	uartRxDataCounter=0;
	__enable_irq();

	uartLastStatus=UART_STATUS_SUCCESS;
	return length;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	uint8_t data = uartRxBuffer[0];

	if (uartDataReceivedCbk!=NULL) {
		uartRxDataCounter=0;
		HAL_UART_Receive_IT(&huart6, uartRxBuffer, 1);

		uartDataReceivedCbk(data);
	}
	else {
		uartRxDataCounter++;

		HAL_UART_Receive_IT(&huart6, uartRxBuffer+uartRxDataCounter, 1);
	}
}

void Error_Handler(void)
{
	while (1);
}
