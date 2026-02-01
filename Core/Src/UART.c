/*
 * UART.c
 *
 *  Created on: 1 lut 2026
 *      Author: 48783
 */
#include "UART.h"
#include <stdio.h>
#include "main.h"
uint16_t Number_T;
uint8_t recive;
char UART_buffer[20];
extern UART_HandleTypeDef huart2;
void UART_Recive(void)
{
	HAL_UART_Receive_IT(&huart2, &recive, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
if(huart->Instance==USART2)
{
	if(recive>='0' && recive<='9')
	{
		Number_T=(Number_T*10)+(recive-'0');
	}
	else if (recive==13)
	{
		if (Number_T>100)
				Number_T=100;
		sprintf(UART_buffer, "%d", Number_T);
		Number_T=0;
	}

	}
}
