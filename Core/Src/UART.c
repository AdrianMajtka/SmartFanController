#include "UART.h"
#include <stdio.h>
#include "main.h"
#include "fan_ctrl.h"
#include "app.h"
volatile uint16_t Number_T;
uint8_t recive;
char UART_buffer[20];
extern UART_HandleTypeDef huart2;
extern volatile FAN_State Current_State;
void UART_Recive(void)
{
	HAL_UART_Receive_IT(&huart2, &recive, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
if(huart->Instance==USART2)
{
	static uint16_t temporary; //Zmienna tymczasowa
	if(recive>='0' && recive<='9')
	{
		temporary=(temporary*10)+(recive-'0');
	}
	else if (recive==13)//Sprawdzenie czy wciśnięto enter
	{
		if (temporary>1000)//Bezpiecznik, aby nie przekroczono wartości maksymalnej.
				temporary=1000;
		Number_T=temporary;
		if(Number_T == 0)
					{
						Current_State = FAN_AUTO;
					}
					else
					{
						Current_State = FAN_MANUAL;
					}
		sprintf(UART_buffer, "%d", Number_T);//Zmiana
		temporary=0; //Zerowanie zmiennej przed kolejnym przejsciem funkcji
	}

	HAL_UART_Receive_IT(&huart2, &recive, 1);
	}
}
