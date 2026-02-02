#include "Temp_sensor.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "OLED.h"
#include "fan_ctrl.h"
#include "app.h"

void OLED_Display(char* buffer) //Funkcja odpowiadająca za wyswietlanie
{
	OLED_State screen_state; //Mapowanie stanu wiatraka na OLED
	if (Current_State==FAN_MANUAL)
	{
		screen_state = OLED_MANUAL;
	}
	else if (Current_State==FAN_AUTO)
	{
		float temp=Temp_Read();  //Obliczanie zmiennej temp
		screen_state=OLED_AUTO;
		Temp_Format(temp, buffer); //Konwersja float na string
	}
	else
	{
		screen_state=OLED_ERROR;
	}
	ssd1306_Fill(Black); //Wyczyszczenie ekranu
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


