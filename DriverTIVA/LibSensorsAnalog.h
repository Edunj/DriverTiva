/*
 * OpticSensors.h
 *
 *  Created on: 20/10/2014
 *      Author: User
 */

#ifndef __DRIVERTIVA_LIBSENSORSADC_H__
#define __DRIVERTIVA_LIBSENSORSADC_H__

#include "LibConfigADC.h"

extern float ValorSensorAnalogico(int8_t pin, int8_t tipo);
extern float CmGP2Y0A41Sk0F(int8_t pin);
extern float CmGP2Y0A21YK(int8_t pin);
extern float CmGP2D12(int8_t pin);
#endif /* LIBSENSORSADC_H__ */
