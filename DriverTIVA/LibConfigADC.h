/*  LibConfigADC.h
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
#include <stdint.h>


#ifndef __DRIVERTIVA_LIBCONFIGADC_H_
#define __DRIVERTIVA_LIBCONFIGSADC_H_

extern void InitSensorADC(void);
extern void ConfigSensorADC(int8_t Sensor);
extern int32_t TriggerADC(int8_t Sensor );
extern float LSBToVoltage(int32_t lsb);


#endif
