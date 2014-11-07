/*  Libqei.c
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


#include "Configuration.h"
#include "libqei.h"
#include "Funciones.h"
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "driverlib/qei.h"

#define USEQEI0
#define USEQEI1

#ifdef USEQEI0
uint16_t OverEncoder0 = 0;
uint16_t PulsosEncoder0;
#endif
#ifdef USEQEI1
uint16_t OverEncoder1 = 0;
uint16_t PulsosEncoder1;
#endif




void QeiInit(){

#ifdef USEQEI0
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

#endif

#ifdef USEQEI1
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI1);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
#endif

}

#ifdef USEQEI0
void ManejadorQEI0(){
	//Ha llegado al limite, por lo que se ha movido 2pi radianes

	if(QEI_INTTIMER == 	ROM_QEIIntStatus(QEI0_BASE,1)){ //Limpiamos la interrupcion

	if(ROM_QEIDirectionGet(QEI0_BASE)){
		OverEncoder0++;
	}else{
		OverEncoder0--;
	}

	}
	ROM_QEIIntClear(QEI0_BASE,QEIIntStatus(QEI0_BASE,1));


}
#endif
#ifdef USEQEI1
void ManejadorQEI1(){

	if(QEI_INTTIMER == ROM_QEIIntStatus(QEI1_BASE,1)){

	if(ROM_QEIDirectionGet(QEI1_BASE)){
		OverEncoder1++;
	}else{
		OverEncoder1--;
	}

	}
	ROM_QEIIntClear(QEI1_BASE,QEIIntStatus(QEI1_BASE,1));
}
#endif

void QeiConfigEncoder(uint8_t port,uint32_t pulsos){


#ifdef USEQEI0
	// Puerto 0
	    //
	    // Enable pin PD6 for QEI0 PHA0
	    //
	if(port == QEI0){
	ROM_GPIOPinConfigure(GPIO_PD6_PHA0);
	ROM_GPIOPinTypeQEI(GPIO_PORTD_BASE, GPIO_PIN_6);

	    //
	    // Enable pin PD7 for QEI0 PHB0
	    // First open the lock and select the bits we want to modify in the GPIO commit register.
	    //
	    HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	    HWREG(GPIO_PORTD_BASE + GPIO_O_CR) = 0x80;

	    //
	    // Now modify the configuration of the pins that we unlocked.
	    //
	    ROM_GPIOPinConfigure(GPIO_PD7_PHB0);
	    ROM_GPIOPinTypeQEI(GPIO_PORTD_BASE, GPIO_PIN_7);
	    ROM_QEIConfigure(QEI0_BASE,(QEI_CONFIG_CAPTURE_A_B| QEI_CONFIG_NO_RESET |
	    						QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP),0xFFFFFFFF);
	    //Establecer las interrupciones, inicializar la variable a cero etc

	    PulsosEncoder0 = pulsos;
	    ROM_QEIPositionSet(QEI0_BASE,0);
	    QEIIntRegister(QEI0_BASE,*ManejadorQEI0);
	    ROM_QEIIntEnable(QEI0_BASE,QEI_INTTIMER|QEI_INTINDEX);
	    ROM_QEIEnable(QEI0_BASE);

	}
#endif
#ifdef USEQEI1
	    //Puerto 1
	    // Enable pin PC5 for QEI1 PHA1
	    //
	if(port == QEI1){
	    ROM_GPIOPinConfigure(GPIO_PC5_PHA1);
	    ROM_GPIOPinTypeQEI(GPIO_PORTC_BASE, GPIO_PIN_5);

	    //
	    // Enable pin PC6 for QEI1 PHB1
	    //
	    ROM_GPIOPinConfigure(GPIO_PC6_PHB1);
	    ROM_GPIOPinTypeQEI(GPIO_PORTC_BASE, GPIO_PIN_6);

	    ROM_QEIConfigure(QEI1_BASE,(QEI_CONFIG_CAPTURE_A_B| QEI_CONFIG_NO_RESET |
	    						QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP),0xFFFFFFFF);

	    PulsosEncoder1 = pulsos;
	    ROM_QEIPositionSet(QEI1_BASE,0);
	    QEIIntRegister(QEI1_BASE,*ManejadorQEI1);
	    ROM_QEIIntEnable(QEI1_BASE,QEI_INTTIMER|QEI_INTINDEX);
	    ROM_QEIEnable(QEI1_BASE);
	    ROM_QEIEnable(QEI1_BASE);
	}
#endif



}




//Devuelve el numero de vueltas en radianes

float QeiRotacionEncoder(uint8_t enc){
	float temp = 0.0;
#ifdef USEQEI0
	if(enc == QEI0){
	temp = (float) ( (OverEncoder0* 0xFFFFFFFF +    ROM_QEIPositionGet(QEI0_BASE)) *2* M_PI)/PulsosEncoder0;

	}
#endif
#ifdef USEQEI1
	if(enc == QEI1){
	 temp = (float) ((OverEncoder1* 0xFFFFFFFF + ROM_QEIPositionGet(QEI1_BASE)) *2* M_PI)/PulsosEncoder1;
	}

#endif
return temp;
}


