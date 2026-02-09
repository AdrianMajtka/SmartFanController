/*
 * app.h
 *
 *  Created on: 1 lut 2026
 *      Author: 48783
 */

#ifndef INC_APP_H_
#define INC_APP_H_
#include "fan_ctrl.h"
#include "OLED.h"
#include "Temp_sensor.h"

extern volatile FAN_State Current_State;
void App_Init(void);
void App_Execution(void);
void OLED_app(char* buffer, OLED_State* screen_state);
#endif /* INC_APP_H_ */
