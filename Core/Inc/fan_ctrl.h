#ifndef INC_FAN_CTRL_H_
#define INC_FAN_CTRL_H_
#include "main.h"

extern uint8_t speed;
extern float value;

typedef enum
{
	FAN_AUTO, //Sterowanie z czujnika temperatury
	FAN_MANUAL, //Ręczne wpisywanie wartości
	FAN_ERROR //Ustawienie bezpiecznych obrotów w przypadku awarii
}FAN_State;

void FAN_Set_Speed(FAN_State State);
void FAN_Fuse(void);

#endif /* INC_FAN_CTRL_H_ */
