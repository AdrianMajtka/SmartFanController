#include "Temp_Sensor.h"
#include "main.h"
#include <stdio.h>

static volatile uint16_t adc_buffer[100];
void Temp_init(ADC_HandleTypeDef* hadc)
{
	HAL_ADC_Start_DMA(hadc, (uint32_t*)adc_buffer, 100);
}

float Temp_Read(void) //Obliczanie temperatury z ADC
{
	uint8_t i;
	uint32_t sum=0;
	float temp;
	for(i=0;i<=99; i++)
	{
		sum=sum+adc_buffer[i];
	}
	temp=(((float)sum/100)*330)/4095; //Przeliczanie średniej wartości ze 100 pomiarów i zamiana na stopnie.
	return temp;
}

void Temp_Format(float temp, char* buffer) //Formatowanie float na string.
{
	sprintf(buffer, "%.2f", temp);

}




