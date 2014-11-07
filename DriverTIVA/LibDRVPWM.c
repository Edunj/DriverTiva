/*  LibDRVPWM.c
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
#include "LibDRVPWM.h"
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "LibConfigPWM.h"
#include "LibServo.h"



#ifdef USEMOTORA
uint8_t MA1,MA2;
#endif
#ifdef USEMOTORB
uint8_t MB1,MB2;
#endif
#ifdef USEMOTORC
uint8_t MC1,MC2;
#endif
#ifdef USEMOTORD
uint8_t MD1,MD2;
#endif
#ifdef USEMOTORE
uint8_t ME1,ME2;
#endif
#ifdef USEMOTORF
uint8_t MF1,MF2;
#endif
#ifdef USEMOTORG
uint8_t MG1,MG2;
#endif
#ifdef USEMOTORH
uint8_t MH1,MH2;
#endif



void configDRVPWM(uint8_t A1,uint8_t A2,uint8_t B1,uint8_t B2,uint8_t C1,uint8_t C2,uint8_t D1,uint8_t D2,
				  uint8_t E1,uint8_t E2,uint8_t F1,uint8_t F2,uint8_t G1,uint8_t G2,uint8_t H1,uint8_t H2){

#ifdef USEMOTORA
	MA1 = A1;
	MA2 = A2;
	ConfigPWM(A1,0,WidthUs);
	ConfigPWM(A2,0,WidthUs);
#endif
#ifdef USEMOTORB
	MB1 = B1;
	MB2 = B2;
	ConfigPWM(B1,0,WidthUs);
	ConfigPWM(B2,0,WidthUs);
#endif
#ifdef USEMOTORC
	MC1 = C1;
	MC2 = C2;
	ConfigPWM(C1,0,WidthUs);
	ConfigPWM(C2,0,WidthUs);
#endif
#ifdef USEMOTORD
	MD1 = D1;
	MD2 = D2;
	ConfigPWM(D1,0,WidthUs);
	ConfigPWM(D2,0,WidthUs);
#endif
#ifdef USEMOTORE
	ME1 = E1;
	ME2 = E2;
	ConfigPWM(E1,0,WidthUs);
	ConfigPWM(E2,0,WidthUs);
#endif
#ifdef USEMOTORF
	MF1 = F1;
	MF2 = F2;
	ConfigPWM(F1,0,WidthUs);
	ConfigPWM(F2,0,WidthUs);
#endif
#ifdef USEMOTORG
	MG1 = G1;
	MG2 = G2;
	ConfigPWM(G1,0,WidthUs);
	ConfigPWM(G2,0,WidthUs);
#endif
#ifdef USEMOTORH
	MH1 = H1;
	MH2 = H2;
	ConfigPWM(H1,0,WidthUs);
	ConfigPWM(H2,0,WidthUs);
#endif
}


void ForWardMotor(uint8_t pot, char motor){
	uint8_t t1,t2;
	switch(motor){
#ifdef USEMOTORA
	case 'A': t1 = MA1,t2 = MA2;break;
#endif
#ifdef USEMOTORB
	case 'B': t1 = MB1,t2 = MB2;break;
#endif
#ifdef USEMOTORC
	case 'C': t1 = MC1,t2 = MC2;break;
#endif
#ifdef USEMOTORD
	case 'D': t1 = MD1,t2 = MD2;break;
#endif
#ifdef USEMOTORE
	case 'E': t1 = ME1,t2 = ME2;break;
#endif
#ifdef USEMOTORF
	case 'F': t1 = MF1,t2 = MF2;break;
#endif
#ifdef USEMOTORG
	case 'G': t1 = MG1,t2 = MG2;break;
#endif
#ifdef USEMOTORH
	case 'H': t1 = MH1,t2 = MH2;break;
#endif
	default:break;
	}
	int16_t temp = (int16_t) (pot*1.80) ;
	WriteServo(t1,temp);
	WriteServo(t2,0);
}

void ReverseMotor(uint8_t pot, char motor){
	uint8_t t1,t2;
	switch(motor){
#ifdef USEMOTORA
	case 'A': t1 = MA1,t2 = MA2;break;
#endif
#ifdef USEMOTORB
	case 'B': t1 = MB1,t2 = MB2;break;
#endif
#ifdef USEMOTORC
	case 'C': t1 = MC1,t2 = MC2;break;
#endif
#ifdef USEMOTORD
	case 'D': t1 = MD1,t2 = MD2;break;
#endif
#ifdef USEMOTORE
	case 'E': t1 = ME1,t2 = ME2;break;
#endif
#ifdef USEMOTORF
	case 'F': t1 = MF1,t2 = MF2;break;
#endif
#ifdef USEMOTORG
	case 'G': t1 = MG1,t2 = MG2;break;
#endif
#ifdef USEMOTORH
	case 'H': t1 = MH1,t2 = MH2;break;
#endif
	default:break;
	}
	int16_t temp = (int16_t) (pot*1.80) ;
	WriteServo(t2,temp);
	WriteServo(t1,0);
}

void BrakeMotor(char motor){
	uint8_t t1,t2;
	switch(motor){
#ifdef USEMOTORA
	case 'A': t1 = MA1,t2 = MA2;break;
#endif
#ifdef USEMOTORB
	case 'B': t1 = MB1,t2 = MB2;break;
#endif
#ifdef USEMOTORC
	case 'C': t1 = MC1,t2 = MC2;break;
#endif
#ifdef USEMOTORD
	case 'D': t1 = MD1,t2 = MD2;break;
#endif
#ifdef USEMOTORE
	case 'E': t1 = ME1,t2 = ME2;break;
#endif
#ifdef USEMOTORF
	case 'F': t1 = MF1,t2 = MF2;break;
#endif
#ifdef USEMOTORG
	case 'G': t1 = MG1,t2 = MG2;break;
#endif
#ifdef USEMOTORH
	case 'H': t1 = MH1,t2 = MH2;break;
#endif
	default:break;
	}
	WriteServo(t2,180);
	WriteServo(t1,180);
}



