/*
 * LibDRV8833.h
 *
 *  Created on: 14/10/2014
 *      Author: User
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
