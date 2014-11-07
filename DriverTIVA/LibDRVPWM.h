/*  LibDRVPWM.h
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

#ifndef  __DRIVERTIVA_LIBDRVPWM_H_
#define  __DRIVERTIVA_LIBDRVPWM_H_

#include <stdint.h>



extern void configDRVPWM(uint8_t A1,uint8_t A2,uint8_t B1,uint8_t B2,uint8_t C1,uint8_t C2,uint8_t D1,uint8_t D2,
						 uint8_t E1,uint8_t E2,uint8_t F1,uint8_t F2,uint8_t G1,uint8_t G2,uint8_t H1,uint8_t H2);
extern void ForWardMotor(uint8_t pot,char motor);
extern void ReverseMotor(uint8_t pot,char motor);
extern void brakeMotor(char motor);


#endif /* LIBDRV8833_H_ */
