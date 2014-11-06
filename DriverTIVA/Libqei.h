/*
 * libqei.h
 *
 *  Created on: 26/07/2014
 *      Author: User
 */

#ifndef __DRIVERTIVA_LIBQEI_H__
#define __DRIVERTIVA_LIBQEI_H__

#include <stdint.h>


//Configuracion de los puertos QEI
extern void QeiInit();
//Prototipos de funciones de acceso
extern void QeiConfigEncoder(uint8_t port,uint32_t pulsos);
extern float QeiRotacionEncoder(uint8_t enc);


#endif
