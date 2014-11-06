/*
 * Funciones.h
 *
 *  Created on: 01/10/2014
 *      Author: User
 */

#ifndef  __DRIVERTIVA_FUNCIONES_H_
#define  __DRIVERTIVA_FUNCIONES_H_

#include <stdint.h>



//Prototipos
extern uint64_t micros(void);
extern void InitReloj(void);
extern uint32_t  map(uint32_t rangmin,uint32_t rangmax,uint32_t valmin,uint32_t valmax,uint32_t val);
extern uint32_t  mapinv(uint32_t rangmin, uint32_t rangmax, uint32_t valmin, uint32_t valmax, uint32_t val);
extern void odometry (float x0, float y0, float theta0, int64_t t0, int32_t rotl0, int32_t rotr0, float * x1, float * y1,	float * theta1, int64_t * t1, int32_t * rotl1, int32_t * rotr1);
extern float radToDeg(float rad);
extern float degToRad(float deg);
extern float randomNormalValue(const double mean, const double sigma);



#endif /*  __DRIVERTIVA_FUNCIONES_H_ */
