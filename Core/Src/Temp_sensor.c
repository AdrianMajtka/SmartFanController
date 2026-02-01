#include "Temp_Sensor.h"
#include "main.h"
#include <stdio.h>

static uint16_t adc_bufor[100];

void Temp_init(ADC_HandleTypeDef* hadc)
{
	HAL_ADC_Start_DMA(hadc, (uint32_t*)adc_bufor, 100);
}

float Temp_Read(void)
{
	uint8_t i;
	uint32_t suma=0;
	float temp;
	for(i=0;i<=99; i++)
	{
		suma=suma+adc_bufor[i];
	}
	temp=(((float)suma/100)*330)/4095;
	return temp;
}

void Temp_Format(float temp, char* bufor)
{
	sprintf(bufor, "%.2f", temp);

}




