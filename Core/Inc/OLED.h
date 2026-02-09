#ifndef INC_OLED_H_
#define INC_OLED_H_
#include "main.h"



typedef enum
{
	OLED_AUTO, //Wyświetlanie wartości z czujnika
	OLED_MANUAL, //Wyświetlanie wartości wpisanej przez użytkownika (UART)
	OLED_ERROR //Wyświetlanie błędu systemu
}OLED_State;

void OLED_Display(void);


#endif /* INC_OLED_H_ */
