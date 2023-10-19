/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f7xx_it_wrapper.cpp
 * @brief   Interrupt Service Routines wrapper for cpp handler.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f7xx_it.h"
#include "Uart.h"

extern Uart *uart6;

void WRAPPER_InitUsart6(Uart &ref) {
	uart6 = &ref;
	huart6 = uart6->GetHandle();
}

/**
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report end of DMA Rx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  /* Set transmission flag: transfer complete */
  //UartReady = SET;
	if (UartHandle == uart6->GetHandle())
	{
		uart6->ProcessHwEvent(Data_Received);
	}

}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
