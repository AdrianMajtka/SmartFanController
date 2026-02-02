/*
 * fan_ctrl.c
 *
 *  Created on: 1 lut 2026
 *      Author: 48783
 */
#include "fan_ctrl.h"
#include "UART.h"
#include "Temp_sensor.h"
#include "OLED.h"
extern uint16_t Number_T;
extern uint32_t suma;
uint8_t speed =0;
float value;
void FAN_Set_Speed(OLED_State State)
{
	switch(State)
	{
	case OLED_MANUAL:
		TIM3->CCR1=Number_T;
		break;
	case OLED_AUTO:
		value=(((float)suma)/4095)*100;
		TIM3->CCR1=value;
		break;
	}


}
