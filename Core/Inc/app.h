/*
 * app.h
 *
 *  Created on: 1 lut 2026
 *      Author: 48783
 */

#ifndef INC_APP_H_
#define INC_APP_H_
#include "fan_ctrl.h"

extern volatile FAN_State Current_State;
void App_Init(void);
void App_Execution(void);
#endif /* INC_APP_H_ */
