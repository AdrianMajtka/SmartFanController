#ifndef INC_FAN_CTRL_H_
#define INC_FAN_CTRL_H_
#include "main.h"

extern uint8_t speed;
extern float value;

typedef enum
{
	FAN_AUTO,
	FAN_MANUAL,
	FAN_ERROR
}FAN_State;

void FAN_Set_Speed(FAN_State State);

#endif /* INC_FAN_CTRL_H_ */
