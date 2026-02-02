#ifndef INC_TEMP_SENSOR_H_
#define INC_TEMP_SENSOR_H_
#include "main.h"

void Temp_init(ADC_HandleTypeDef* hadc);
float Temp_Read(void);
void Temp_Format(float temp, char* buffer);


#endif /* INC_TEMP_SENSOR_H_ */
