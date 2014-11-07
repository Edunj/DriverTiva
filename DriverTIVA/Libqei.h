/*  Libqei.h
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

#ifndef __DRIVERTIVA_LIBQEI_H__
#define __DRIVERTIVA_LIBQEI_H__

#include <stdint.h>



extern void QeiInit();
extern void QeiConfigEncoder(uint8_t port,uint32_t pulsos);
extern float QeiRotacionEncoder(uint8_t enc);
extern void ManejadorQEI0();
extern void ManejadorQEI1();

#endif
