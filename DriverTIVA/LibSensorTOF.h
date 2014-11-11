/*  LibSensorTOF.h
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

#ifndef __DRIVERTIVA_LIBSENSORTOF_H__
#define __DRIVERTIVA_LIBSENSORTOF_H__

#include <stdint.h>





//
//! This is the variable for the constant time of fly
//
static float ConstanTFly=  58;



//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void HandleTrigger();
extern void TOFTrigger();
extern void TOFEchoInit(uint8_t GPIOPin);
extern void TOFProcess();
extern void SetConstantTOF(float value);
extern float GetValueTOFPin(uint8_t GPIOPin);

#endif /* __DRIVERTIVA_LIBSENSORTOF_H__ */
