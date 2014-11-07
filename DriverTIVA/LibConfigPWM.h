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


//Width to signal PWM for the servos
#define USEGENPWM0
#define USEOUTPWM0
#define USEOUTPWM1
#define USEOUTPWM2
#define USEOUTPWM3
#define USEOUTPWM4
#define USEOUTPWM5
#define USEOUTPWM6


static  uint16_t Min[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static uint16_t Max[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//Ancho de pulso
static uint32_t WidthUs = 20000;
//Prototypes
extern int initPWMS(int  periodMs );
extern void ConfigPWM(uint8_t pin,uint16_t min, uint16_t max );
extern void TurnOffPWM(uint8_t servo);



#endif

