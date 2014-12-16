/*  LibConfigPWM.h
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
#ifndef __DRIVERTIVA_LIBCONFIGPWM_H__
#define __DRIVERTIVA_LIBCONFIGPWM_H__

#include <stdint.h>


//
//! This is the variables for minimum period of PWM signal
//
extern  uint16_t Min[16];

//
//! This is the variables for maximum period of PWM signal
//
extern  uint16_t Max[16];


//
//! This is the variable for Period of PWM signal
//
extern uint32_t WidthUs;





//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void initPWMS(int  periodMs );
extern void ConfigPWM(uint8_t PWMpin,uint16_t min, uint16_t max );
extern void TurnOffPWM(uint8_t PWMpin);



#endif /*__DRIVERTIVA_LIBCONFIGPWM_H__*/

