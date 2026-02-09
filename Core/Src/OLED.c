#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "OLED.h"
#include "app.h"

OLED_State screen_state;
void OLED_Display(void) //Funkcja odpowiadająca za wyswietlanie
{
	char buffer[32]; //Bufor lokalny
	OLED_app(buffer, &screen_state);
	ssd1306_Fill(Black);
	switch(screen_state)
	{
		case OLED_AUTO:
			ssd1306_SetCursor(0, 20);
			ssd1306_WriteString(buffer, Font_11x18, White);
			break;
		case OLED_ERROR:

			ssd1306_SetCursor(0,20);
			ssd1306_WriteString("ERROR", Font_16x26, White);
			break;
		case OLED_MANUAL:
			ssd1306_SetCursor(0,20);
			ssd1306_WriteString(buffer, Font_11x18, White);
			break;
	}
	ssd1306_UpdateScreen();
}


