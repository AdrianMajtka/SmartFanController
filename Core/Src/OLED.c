#include "Temp_sensor.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "OLED.h"
#include "fan_ctrl.h"
#include "app.h"

extern volatile FAN_State Current_State;
void OLED_Display(void) //Funkcja odpowiadająca za wyswietlanie
{
	char buffer[32]; //Bufor lokalny
	OLED_State screen_state; //Mapowanie stanu wiatraka na OLED
	float temp=Temp_Read();


	if (temp<10||temp>95)
	{
		screen_state = OLED_ERROR;
	}

	else if (Current_State==FAN_MANUAL)
	{
		screen_state = OLED_MANUAL;
		temp = Temp_Read();
		sprintf(buffer, "Man: %.2f C", temp);
	}
	else if (Current_State==FAN_AUTO)
	{
		screen_state = OLED_AUTO;
		temp = Temp_Read();
		sprintf(buffer, "Auto: %.2f C", temp);
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


