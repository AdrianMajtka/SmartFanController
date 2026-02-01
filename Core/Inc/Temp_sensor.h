/*
 * Temp_sensor.h
 *
 *  Created on: 1 lut 2026
 *      Author: 48783
 */

#ifndef INC_TEMP_SENSOR_H_
#define INC_TEMP_SENSOR_H_
$include "main.h"

float TEMP_Read(void);

void TEMP_Format(float value, char* buffor);


#endif /* INC_TEMP_SENSOR_H_ */
