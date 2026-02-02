//Funkcja sterująca prędkością wentylatora.

#include "app.h"
#include "fan_ctrl.h"
#include "UART.h"


volatile FAN_State Current_State;
void App_Init(void) //Inicjalizacja funkcji App
{
	Current_State=FAN_AUTO;
}
void App_Execution(void)
{
	FAN_Set_Speed(Current_State);

}
