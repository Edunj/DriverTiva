/*  Funciones.h
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


//*****************************************************************************
//
//! Returns the number of microseconds since run InitReloj.
//!
//! This function returns the interrupt number of microseconds since run the
//! microcontroller.
//!
//! \return uint64_t microseconds.
//
//*****************************************************************************
uint64_t
micros(void){
	return (TimerValueGet64(WTIMER0_BASE)/ ((int64_t)divisor));
}



//*****************************************************************************
//
//! Init the clock system in WTIMER0. Use both register, Register A and REgisterB
//!
//! Config the count in up mode.
//!
//! \return none.
//
//*****************************************************************************
void
InitReloj(void){

	SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
	TimerDisable(WTIMER0_BASE, TIMER_BOTH);
	TimerClockSourceSet(WTIMER0_BASE,TIMER_CLOCK_SYSTEM);

	 TimerConfigure(WTIMER0_BASE,TIMER_CFG_PERIODIC_UP);


	 uint32_t frecCTL = SysCtlClockGet();
	 divisor = (int32_t ) (frecCTL / 1e6);

	 TimerEnable(WTIMER0_BASE,TIMER_A);

	 TimerLoadSet64(WTIMER0_BASE,0xFFFFFFFFFFFFFFFF);
}

//*****************************************************************************
//
//! Returns the convert of rad in Deg
//!
//! \param rad is the number of radians.
//!
//! This function returns the number of degs of rad.
//!
//! \return number of degres in rad.
//
//*****************************************************************************
float
radToDeg(float rad){

 return (rad*180.0)/M_PI;
 }

float degToRad(float deg){
return (deg*M_PI)/180.0;
}



//*****************************************************************************
//
//! This function use a odometry of the differential wheel with the parameters
//! radio and d defines in the configuration.h
//! This function take the last points x0, y0, rotl0, rotr0, t0, theta0 and
//!	generate the new points x1,y1,theta1, t1,rotl1,rotr1.
//!
//! \param x0
//! \param y0
//! \param theta0
//! \param t0
//! \param rotl0
//! \param rotr0
//! \param x1
//! \param y1
//! \param theta1
//! \param t1
//! \param rotl1
//! \param rotr1
//!
//!  Radio is the radius of the wheel in meters, d is the distance between wheels in
//!  meters.
//!
//! This function take the last points x0, y0, rotl0, rotr0, t0, theta0 and
//!	generate the new points x1,y1,theta1, t1,rotl1,rotr1
//!
//! \return Returns none, the pointers arguments are changed.
//!
//
//*****************************************************************************
void
odometry (float x0, float y0, float theta0, int64_t t0, int32_t rotl0, int32_t rotr0,
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
	//DeltaT is in us
	VRL = (((encI - rotl0) * radio)/DeltaT) * 1e6;
	VRR = (((encD - rotr0) * radio)/DeltaT) * 1e6;
	VCM= (VRL + VRR)/2.0;

	//Calculo de theta1

	*theta1 = theta0 + ((VCM*DeltaT)/d);

	//calculo de x1 e y1
	// *x1 = (x0 + (VCM*DeltaT)*cosf(*theta0));
	// *y1 = (y0 + (VCM*DeltaT)*sinf(*theta0));


}

//*****************************************************************************
//
//! Returns the interpolation of val in the range valmin, valmax, using
//! rangmax and rangmin for the value val
//!
//! \param rangmin min rang for the output data.
//! \param rangmax max rang for the output data.
//! \param valmin  min rang for the imput data.
//! \param valmax  max rang for the imput data.
//! \param val  value between valmin and valmax.
//!
//! Val is a value between valmax and valmin, the return function is the
//! interpolation value between rangmax and rangmin.
//!
//! \return Returns a uint32_t value.
//!
//*****************************************************************************
uint32_t
map(uint32_t rangmin, uint32_t rangmax, uint32_t valmin, uint32_t valmax, uint32_t val){

	float temp1 = (float)(rangmax -rangmin);
	float temp2 = (float)(valmax -valmin);
	uint32_t temporal = (uint32_t)( round((temp1/temp2)*(float)val + rangmin));
	return  temporal;
}


//*****************************************************************************
//
//! Returns the inversal interpolation of val in the range valmin, valmax, using
//! rangmax and rangmin for the value val
//!
//! \param rangmin min rang for the output data.
//! \param rangmax max rang for the output data.
//! \param valmin  min rang for the imput data.
//! \param valmax  max rang for the imput data.
//! \param val  value between valmin and valmax.
//!
//! Val is a value between valmax and valmin, the return function is the
//! interpolation value between rangmax and rangmin.
//!
//! \return Returns a uint32_t value.
//!
//*****************************************************************************
uint32_t
mapinv(uint32_t rangmin, uint32_t rangmax, uint32_t valmin, uint32_t valmax, uint32_t val){

	float temp1 = (float)(rangmax -rangmin);
	float temp2 = (float)(valmax -valmin);
	uint32_t temporal = (uint32_t)( round((temp1/temp2)*(float)(val - valmin)));
	return  temporal;
}


//*****************************************************************************
//
//! Returns  a random value in the gaussian distribution with mean mean and
//! standard desviation sigma.
//!
//! \param mean is the mean of the gaussian distribution
//! \param sigma is the standard desviation
//!
//! Returns  a random value in the gaussian distribution with mean mean and
//! standard desviation sigma.
//!
//! \return Returns a float random value.
//!
//
//*****************************************************************************
float
randomNormalValue(const double mean, const double sigma){
	 double U,V ;
	 double variance = sigma*sigma;
	U = ( double)(( rand() % (RAND_MAX) ) / (double)(RAND_MAX));
	V = (double)(( rand() % (RAND_MAX) ) / (double)(RAND_MAX));
	const double X = sqrt(-2*log(U))*sin(2*M_PI*V);
	return X * sqrt(variance) + mean;
}




