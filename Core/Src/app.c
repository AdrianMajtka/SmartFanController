#include "app.h"
#include "fan_ctrl.h"
#include "UART.h"


volatile FAN_State Current_State;
void App_Init(void)
{
	Current_State=FAN_AUTO;
}
void App_Execution(void)
{
	FAN_Set_Speed(Current_State);

}
