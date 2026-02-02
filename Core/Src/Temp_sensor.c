#include "Temp_Sensor.h"
#include "main.h"
#include <stdio.h>

static uint16_t adc_buffer[100];
uint32_t suma=0;
void Temp_init(ADC_HandleTypeDef* hadc)
{
	HAL_ADC_Start_DMA(hadc, (uint32_t*)adc_buffer, 100);
}

float Temp_Read(void)
{
	uint8_t i;

	float temp;
	for(i=0;i<=99; i++)
	{
		suma=suma+adc_buffer[i];
	}
	temp=(((float)suma/100)*330)/4095;
	return temp;
}

void Temp_Format(float temp, char* buffer)
{
	sprintf(buffer, "%.2f", temp);

}




