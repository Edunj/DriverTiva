/*  LibSensorsAnalog.c
    Copyright (C) 2012-2013 Eduardo del Nogal Jiménez

    This is part of DriverTiva.

    DriverTiva is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DriverTiva is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with DriverTiva.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __DRIVERTIVA_LIBSENSORSADC_H__
#define __DRIVERTIVA_LIBSENSORSADC_H__

#include "LibConfigADC.h"



//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern float ValorSensorAnalogico(int8_t AdcPin, int8_t type);
extern float CmGP2Y0A41Sk0F(int8_t AdcPin);
extern float CmGP2Y0A21YK(int8_t AdcPin);
extern float CmGP2D12(int8_t AdcPin);


#endif /* __DRIVERTIVA_LIBSENSORSADC_H__ */
