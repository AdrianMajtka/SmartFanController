//Funkcja sterująca prędkością wentylatora.

#include "app.h"
#include "fan_ctrl.h"
#include "UART.h"
#include "OLED.h"
#include "Temp_sensor.h"


volatile FAN_State Current_State;
void App_Init(void) //Inicjalizacja funkcji App
{
	Current_State=FAN_AUTO;
}
void App_Execution(void)
{
	FAN_Set_Speed(Current_State);
	OLED_Display();
}
void OLED_app(char* buffer, OLED_State* screen_state)
{


	float temp=Temp_Read();
	if (temp<10||temp>95)
		{
			*screen_state = OLED_ERROR;
		}

		else if (Current_State==FAN_MANUAL)
		{
			*screen_state = OLED_MANUAL;
			sprintf(buffer, "Man: %.2f C", temp);
		}
		else if (Current_State==FAN_AUTO)
		{
			*screen_state = OLED_AUTO;
			sprintf(buffer, "Auto: %.2f C", temp);
		}

}
