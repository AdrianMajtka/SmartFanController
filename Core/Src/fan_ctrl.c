#include "fan_ctrl.h"
#include "UART.h"
#include "Temp_sensor.h"
#include "OLED.h"
extern volatile uint16_t Number_T;
extern uint32_t suma;
uint8_t speed =0;
float value;

void FAN_Set_Speed(FAN_State State) //Obsługa stanów wentylatora
{
	uint16_t pwm_value;
	switch(State)
	{
	case FAN_MANUAL:  //Ręczne wpisywanie przez UART
		TIM3->CCR1=Number_T;
		break;
	case FAN_AUTO: //Automatyczne sterowanie.
		value=Temp_Read();
		if (value<20)
		{
			pwm_value=0;
		}
		else
		{
			pwm_value=(value-20)*20+400;
		}
		if (pwm_value>1000)
		{
			pwm_value = 1000;
		}
		TIM3->CCR1=pwm_value;
		break;
	case FAN_ERROR:
		TIM3->CCR1=500; //Bezpieczna wartość aby system się nie przegrzał nawet przy błędzie.
		break;
	}


}
