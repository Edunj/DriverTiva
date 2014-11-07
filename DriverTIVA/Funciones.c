/*
 * Funciones.c
 *
 *  Created on: 01/10/2014
 *      Author: User
 */
#include "Funciones.h"
#include <stdbool.h>
#include <stdlib.h>
#include "math.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "Libqei.h"
#include "Configuration.h"

static int32_t divisor;



uint64_t micros(void){
	return (TimerValueGet64(WTIMER0_BASE)/ ((int64_t)divisor));
}




void InitReloj(void){

	SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
	TimerDisable(WTIMER0_BASE, TIMER_BOTH);
	TimerClockSourceSet(WTIMER0_BASE,TIMER_CLOCK_SYSTEM);

	 TimerConfigure(WTIMER0_BASE,TIMER_CFG_PERIODIC_UP);


	 uint32_t frecCTL = SysCtlClockGet();
	 divisor = (int32_t ) (frecCTL / 1e6);

	 TimerEnable(WTIMER0_BASE,TIMER_A);

	 TimerLoadSet64(WTIMER0_BASE,0xFFFFFFFFFFFFFFFF);



}


float radToDeg(float rad){

 return (rad*180.0)/M_PI;
 }

float degToRad(float deg){
return (deg*M_PI)/180.0;
}

/*Odometry para robot rotatorio de tres ruedas con rueda trasera loca.
 *
 *Comprobar la funcion pasandole los puntos de la clase
 */



void odometry (float x0, float y0, float theta0, int64_t t0, int32_t rotl0, int32_t rotr0,
			   float * x1, float * y1,	float * theta1, int64_t * t1, int32_t * rotl1, int32_t * rotr1){

	//Sistema de unidades: metros, radianes, segundos
	float   VRL, VRR,VCM;


	//Suponemos que hemos recogido ya los encoder (encD, encI, y la diferencia de tiempos --> DeltaT
	float encD, encI, DeltaT;
	encD = 0; //Aqui usamos las funciones de la libreria qei
	encI = 0;
	*t1 = micros();
	DeltaT = (float)(*t1-t0);
	//recogida de los encoder
	//Recogida del tiempo
	*rotr1 = encD;
	*rotl1 = encI;
	//calculo de las velocidades de las ruedas
	VRL = ((encI - rotl0) * radio)/DeltaT;
	VRR = ((encD - rotr0) * radio)/DeltaT;
	VCM= (VRL + VRR)/2.0;

	//Calculo de theta1

	*theta1 = theta0 + (VCM/(radio*2))*DeltaT;

	//calculo de x1 e y1
	 *x1 = (x0 + (VCM*DeltaT)*cosf(*theta1));
	 *y1 = (y0 +(VCM*DeltaT)*sinf(*theta1));


}

uint32_t  map(uint32_t rangmin, uint32_t rangmax, uint32_t valmin, uint32_t valmax, uint32_t val){

	float temp1 = (float)(rangmax -rangmin);
	float temp2 = (float)(valmax -valmin);
	uint32_t temporal = (uint32_t)( round((temp1/temp2)*(float)val + rangmin));
	return  temporal;
}

uint32_t  mapinv(uint32_t rangmin, uint32_t rangmax, uint32_t valmin, uint32_t valmax, uint32_t val){

	float temp1 = (float)(rangmax -rangmin);
	float temp2 = (float)(valmax -valmin);
	uint32_t temporal = (uint32_t)( round((temp1/temp2)*(float)(val - valmin)));
	return  temporal;
}

//Con esta funcion podemos extraer de una distribucion con media mean y sigma sigma, una variable aleatoria
//
float randomNormalValue(const double mean, const double sigma){
	 double U,V ;
	 double variance = sigma*sigma;
	U = ( double)(( rand() % (RAND_MAX) ) / (double)(RAND_MAX));
	V = (double)(( rand() % (RAND_MAX) ) / (double)(RAND_MAX));
	const double X = sqrt(-2*log(U))*sin(2*M_PI*V);
	return X * sqrt(variance) + mean;
}




