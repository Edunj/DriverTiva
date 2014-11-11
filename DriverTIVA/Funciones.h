/*  Funciones.h
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

#ifndef  __DRIVERTIVA_FUNCIONES_H_
#define  __DRIVERTIVA_FUNCIONES_H_

#include <stdint.h>



//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern uint64_t micros(void);
extern void InitReloj(void);
extern uint32_t  map(uint32_t rangmin,uint32_t rangmax,uint32_t valmin,uint32_t valmax,uint32_t val);
extern uint32_t  mapinv(uint32_t rangmin, uint32_t rangmax, uint32_t valmin, uint32_t valmax, uint32_t val);
extern void odometry (float x0, float y0, float theta0, int64_t t0, int32_t rotl0, int32_t rotr0, float * x1, float * y1,	float * theta1, int64_t * t1, int32_t * rotl1, int32_t * rotr1);
extern float radToDeg(float rad);
extern float degToRad(float deg);
extern float randomNormalValue(const double mean, const double sigma);



#endif /*  __DRIVERTIVA_FUNCIONES_H_ */
