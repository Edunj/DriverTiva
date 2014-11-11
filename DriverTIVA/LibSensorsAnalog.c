/*  LibSensorsAnalog.h
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

#include "LibSensorsAnalog.h"



//*****************************************************************************
//
//! This function, return a distance measure with a sensor in a pin.
//!
//! \param AdcPin is ADC's pin of system GPIO.
//! \param type is type of sensor put in this pin.
//!
//! Measure distance in a pin AdcPin with the type specified.
//!
//! The \e AdcPin parameter can take on the following values:
//!
//! - \b ADC0  - Pin PE3
//! - \b ADC1  - Pin PE2
//! - \b ADC2  - Pin PE1
//! - \b ADC3  - Pin PE0
//! - \b ADC4  - Pin PD3
//! - \b ADC5  - Pin PD2
//! - \b ADC6  - Pin PD1
//! - \b ADC7  - Pin PD0
//! - \b ADC8  - Pin PE5
//! - \b ADC9  - Pin PE4
//! - \b ADC10 - Pin PB4
//! - \b ADC11 - Pin PB5
//!
//! The \e type parameter can take on the following values:
//!
//! - \b GP2Y0A41SFK0F  - Sensor GP2Y0A41SFK0F
//! - \b GP2Y0A21YK     - Sensor GP2Y0A21YK
//! - \b GP2D12         - Sensor GP2D12
//!
//! \return a distance measure with this sensor in this pin.
//
//*****************************************************************************
float
ValorSensorAnalogico(int8_t AdcPin, int8_t type){
float valor;
	switch(type){
	case 0:{
		valor = CmGP2Y0A41Sk0F(AdcPin);
		break;
	}
	case 1:{
		valor = CmGP2Y0A21YK(AdcPin);
		break;
	}
	case 2:{
		valor = CmGP2D12(AdcPin);
		break;
	}
	default:break;
	}
	return valor ;

}



//*****************************************************************************
//
//! Return a distance measure with a GP2Y0A41Sk0F sensor.
//!
//! \param AdcPin is ADC's pin of system GPIO.
//!
//! Return a distance measure with a GP2Y0A41Sk0F sensor.
//!
//! The \e AdcPin parameter can take on the following values:
//!
//! - \b ADC0  - Pin PE3
//! - \b ADC1  - Pin PE2
//! - \b ADC2  - Pin PE1
//! - \b ADC3  - Pin PE0
//! - \b ADC4  - Pin PD3
//! - \b ADC5  - Pin PD2
//! - \b ADC6  - Pin PD1
//! - \b ADC7  - Pin PD0
//! - \b ADC8  - Pin PE5
//! - \b ADC9  - Pin PE4
//! - \b ADC10 - Pin PB4
//! - \b ADC11 - Pin PB5
//!
//! \return a distance measure with a GP2Y0A41Sk0F sensor..
//
//*****************************************************************************
float
CmGP2Y0A41Sk0F(int8_t AdcPin){

	const int8_t index = 6;
	float x[6] = {6,  10,   12,  16,   20,   30},
		  y[6] = {2, 1.25, 1.05, 0.8, 0.65, 0.4 }, temp;
	float voltage;
	voltage = LSBToVoltage(TriggerADC(AdcPin));

	temp = voltage/1000;
	int i;
		for(i=0;i<index;i++){
			if(temp==y[i]){
				return x[i];
			}else if(i<index-1){
					if(temp > y[i+1]){
				//Utilizando la ecuacion de la recta que pasa por dos puntos
				/*
				 *  y - y1   y2 - y1                    y2 - y1
				 *  ------ = -------;   x = -(y1 -y) /  ------- + x1
				 *  x - x1   x2 - x1                    x2 - x1
				 */
					float pendiente = (y[i] -y[i+1])/(x[i]-x[i+1]);
					//temp=map(y[i],y[i-1],x[i],x[i-1],voltage);
				return (-(y[i+1] - temp)/pendiente+x[i+1]);
					}
			}
		}
		return 0;
}


//*****************************************************************************
//
//! Return a distance measure with a GP2Y0A21YK sensor.
//!
//! \param AdcPin is ADC's pin of system GPIO.
//!
//! Return a distance measure with a GP2Y0A21YK sensor.
//!
//! The \e AdcPin parameter can take on the following values:
//!
//! - \b ADC0  - Pin PE3
//! - \b ADC1  - Pin PE2
//! - \b ADC2  - Pin PE1
//! - \b ADC3  - Pin PE0
//! - \b ADC4  - Pin PD3
//! - \b ADC5  - Pin PD2
//! - \b ADC6  - Pin PD1
//! - \b ADC7  - Pin PD0
//! - \b ADC8  - Pin PE5
//! - \b ADC9  - Pin PE4
//! - \b ADC10 - Pin PB4
//! - \b ADC11 - Pin PB5
//!
//! \return a distance measure with a GP2Y0A21YK sensor..
//
//*****************************************************************************
float
CmGP2Y0A21YK(int8_t AdcPin){
	const int8_t index = 12;
	float x[12] = {6,     8,   10,   15,   20,  25,  30,   40,   50,  60,  70,   80},
		  y[12] = {3.15, 2.74, 2.3, 1.65, 1.3, 1.08, 0.93, 0.74, 0.6, 0.5, 0.45, 0.4}, temp;
	int8_t voltage;
	int i;
	voltage = LSBToVoltage(TriggerADC(AdcPin));


	//Formula para  el sensor GP2Y0A21YK
	temp = (float)voltage;
	for(i=0;i<index;i++){
		if(temp==y[i]){
			return x[i];
		}else if(i<index-1){
				if(temp > y[i-1]){
				//Utilizando la ecuacion de la recta que pasa por dos puntos
				/*
				 *  y - y1   y2 - y1                    y2 - y1
				 *  ------ = -------;   x = -(y1 -y) /  ------- + x1
				 *  x - x1   x2 - x1                    x2 - x1
				 */
					float pendiente = (y[i] -y[i+1])/(x[i]-x[i+1]);
				return (-(y[i+1] - temp)/pendiente+x[i+1]);
					}
		}
	}
	return 0;
}


//*****************************************************************************
//
//! Return a distance measure with a GP2D12 sensor.
//!
//! \param AdcPin is ADC's pin of system GPIO.
//!
//! Return a distance measure with a GP2D12 sensor.
//!
//! The \e AdcPin parameter can take on the following values:
//!
//! - \b ADC0  - Pin PE3
//! - \b ADC1  - Pin PE2
//! - \b ADC2  - Pin PE1
//! - \b ADC3  - Pin PE0
//! - \b ADC4  - Pin PD3
//! - \b ADC5  - Pin PD2
//! - \b ADC6  - Pin PD1
//! - \b ADC7  - Pin PD0
//! - \b ADC8  - Pin PE5
//! - \b ADC9  - Pin PE4
//! - \b ADC10 - Pin PB4
//! - \b ADC11 - Pin PB5
//!
//! \return a distance measure with a GP2D12 sensor..
//
//*****************************************************************************
float
CmGP2D12(int8_t AdcPin){
	const int8_t index = 13;
	float x[13] = { 8,   10,  12,  14.5,  20,  25,   30,   35,   40,   50,   60,   70,   80},
		  y[13] = {2.6, 2.4, 2.15, 1.85, 1.4, 1.16, 0.95, 0.85, 0.75, 0.62, 0.52, 0.47, 0.4 }, temp;
	int8_t voltage;
	int i;
	voltage = LSBToVoltage(TriggerADC(AdcPin));


	//Formula para  el sensor GP2D12
	temp = (float)voltage;
	for(i=0;i<index;i++){
		if(temp==y[i]){
			return x[i];
		}else if(i<index-1){
				if(temp > y[i-1]){
				//Utilizando la ecuacion de la recta que pasa por dos puntos
				/*
				 *  y - y1   y2 - y1                    y2 - y1
				 *  ------ = -------;   x = -(y1 -y) /  ------- + x1
				 *  x - x1   x2 - x1                    x2 - x1
				 */
					float pendiente = (y[i] -y[i+1])/(x[i]-x[i+1]);
				return (-(y[i+1] - temp)/pendiente+x[i+1]);
					}
		}
	}
	return 0;
}
