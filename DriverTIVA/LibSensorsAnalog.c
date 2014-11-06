/*
 * OpticSensors.c
 *
 *  Created on: 20/10/2014
 *      Author: User
 */


#include "LibSensorsAnalog.h"




float ValorSensorAnalogico(int8_t pin, int8_t tipo){
float valor;
	switch(tipo){
	case 0:{
		valor = CmGP2Y0A41Sk0F(pin);
		break;
	}
	case 1:{
		valor = CmGP2Y0A21YK(pin);
		break;
	}
	case 2:{
		valor = CmGP2D12(pin);
		break;
	}
	default:break;
	}
	return valor ;

}




float CmGP2Y0A41Sk0F(int8_t pin){
	//float temp0,temp1;
	const int8_t index = 6;
	float x[6] = {6,  10,   12,  16,   20,   30},
		  y[6] = {2, 1.25, 1.05, 0.8, 0.65, 0.4 }, temp;
	float voltage;
	voltage = LSBToVoltage(TriggerADC(pin));


	/*//Formula para  el sensor GP2Y0A41Sk0F utilizando  minimos cuadrados para la aproximacion
	temp0 = (float)voltage;
	temp1 = -0.0003*pow(voltage,3);
	temp1 += 0.0186*pow(voltage,2);
	temp1 += -0.4224*voltage;
	temp1 += 3,9166;
	return (int8_t)temp1;
*/
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

float CmGP2Y0A21YK(int8_t pin){
	const int8_t index = 12;
	float x[12] = {6,     8,   10,   15,   20,  25,  30,   40,   50,  60,  70,   80},
		  y[12] = {3.15, 2.74, 2.3, 1.65, 1.3, 1.08, 0.93, 0.74, 0.6, 0.5, 0.45, 0.4}, temp;
	int8_t voltage;
	int i;
	voltage = LSBToVoltage(TriggerADC(pin));


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


float CmGP2D12(int8_t pin){
	const int8_t index = 13;
	float x[13] = { 8,   10,  12,  14.5,  20,  25,   30,   35,   40,   50,   60,   70,   80},
		  y[13] = {2.6, 2.4, 2.15, 1.85, 1.4, 1.16, 0.95, 0.85, 0.75, 0.62, 0.52, 0.47, 0.4 }, temp;
	int8_t voltage;
	int i;
	voltage = LSBToVoltage(TriggerADC(pin));


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
