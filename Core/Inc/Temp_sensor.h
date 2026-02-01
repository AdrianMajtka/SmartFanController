/*
 * Temp_sensor.h
 *
 *  Created on: 1 lut 2026
 *      Author: 48783
 */

#ifndef INC_TEMP_SENSOR_H_
#define INC_TEMP_SENSOR_H_
#include "main.h"

void Temp_init(ADC_HandleTypeDef* hadc);
float Temp_Read(void);
void Temp_Format(float suma, char* buffor);


#endif /* INC_TEMP_SENSOR_H_ */
