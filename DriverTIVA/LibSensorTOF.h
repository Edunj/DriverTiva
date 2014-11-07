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

//Existen pines de algunos puertos que no pueden ser configurados, pero con la ventaja de
//que cada byte se corresponde con un puerto entero, así podemos saber si de ese puerto existe
//algún pin a poner en la interrupción





static float CteVuelo =  58;


extern void HandleTrigger();
extern void TOFTrigger();
extern void TOFEchoInit(uint8_t GPIOPin);
extern void TOFProcess();
extern void EstablecerCteVuelo(float valor);
extern float SensorPuertoPin(uint8_t pin);
#endif /* LIBULTRASONIC_H_ */
