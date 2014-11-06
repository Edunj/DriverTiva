/*
 * ServoDefine.h
 *
 *  Created on: 19/03/2014
 *      Author: Admin
 */
#ifndef __DRIVERTIVA_LIBCONFIGPWM_H__
#define __DRIVERTIVA_LIBCONFIGPWM_H__

#include <stdint.h>


//Width to signal PWM for the servos
#define USEGENPWM0
#define USEOUTPWM0
#define USEOUTPWM1
#define USEOUTPWM2
#define USEOUTPWM3
#define USEOUTPWM4
#define USEOUTPWM5
#define USEOUTPWM6


static  uint16_t Min[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static uint16_t Max[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//Ancho de pulso
static uint32_t WidthUs = 20000;
//Prototypes
extern int initPWMS(int  periodMs );
extern void ConfigPWM(uint8_t pin,uint16_t min, uint16_t max );
extern void TurnOffPWM(uint8_t servo);



#endif

