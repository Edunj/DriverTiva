/*
 * LibUltrasonic.h
 *
 *  Created on: 01/10/2014
 *      Author: User
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
