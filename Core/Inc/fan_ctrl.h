/*
 * fam_ctrl.h
 *
 *  Created on: 1 lut 2026
 *      Author: 48783
 */

#ifndef INC_FAN_CTRL_H_
#define INC_FAN_CTRL_H_
#include "main.h"
#include "OLED.h"
#include "UART.h"

extern uint8_t speed;
extern float value;

void FAN_Set_Speed(OLED_State State);

#endif /* INC_FAN_CTRL_H_ */
