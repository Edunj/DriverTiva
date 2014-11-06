/*
 * LibServo.h
 *
 *  Created on: 20/10/2014
 *      Author: User
 */

#ifndef __DRIVERTIVA_LIBSERVO_H_
#define __DRIVERTIVA_LIBSERVO_H_

#include <stdint.h>
#include "LibConfigPWM.h"


extern void WriteServo(int8_t servo,int16_t ang);
extern uint32_t GetAngServo(int8_t servo);
extern void WriteServoInc(int8_t servo, int16_t inc);


#endif /*  __DRIVERTIVA_LIBSERVO_H_ */
