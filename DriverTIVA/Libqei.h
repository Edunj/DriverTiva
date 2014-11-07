/*
 * libqei.h
 *
 *  Created on: 26/07/2014
 *      Author: User
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
