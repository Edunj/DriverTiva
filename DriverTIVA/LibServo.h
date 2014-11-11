/*  LibServo.h
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

#ifndef __DRIVERTIVA_LIBSERVO_H_
#define __DRIVERTIVA_LIBSERVO_H_

#include <stdint.h>
#include "LibConfigPWM.h"



//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void SetAngServo(int8_t PWMpin,int16_t ang);
extern uint32_t GetAngServo(int8_t PWMpin);
extern void WriteServoInc(int8_t PWMpin, int16_t inc);


#endif /*  __DRIVERTIVA_LIBSERVO_H_ */
