#include "Temp_sensor.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "OLED.h"


void OLED_Display(OLED_State State, char* buffer)
{
	ssd1306_Fill(Black);
	switch(State)
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


