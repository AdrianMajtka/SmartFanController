#include "main.h"
#ifndef INC_OLED_H_
#define INC_OLED_H_


typedef enum
{
	OLED_AUTO,
	OLED_ERROR,
	OLED_MANUAL
}OLED_State;

void OLED_Display(OLED_State state, char* bufor);


#endif /* INC_OLED_H_ */
