#ifndef INC_OLED_H_
#define INC_OLED_H_
#include "main.h"



typedef enum //Lista stanów Wyświetlacza
{
	OLED_AUTO,
	OLED_ERROR,
	OLED_MANUAL
}OLED_State;

void OLED_Display(void);


#endif /* INC_OLED_H_ */
