/*
 * Libqei.c
 *
 *  Created on: 26/07/2014
 *      Author: User
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



#ifdef USEQEI0
int16_t PulsosEncoder0;
#endif
#ifdef USEQEI1
int16_t PulsosEncoder1;
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
	    // QEIIntRegister(QEI0_BASE,*ManejadorQEI0);
	    // QEIIntEnable(QEI0_BASE,QEI_INTTIMER|QEI_INTINDEX);
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
	   //  QEIIntRegister(QEI1_BASE,*ManejadorQEI1);
	  //   QEIIntEnable(QEI1_BASE,QEI_INTTIMER|QEI_INTINDEX);
	 //   QEIEnable(QEI1_BASE);
	    ROM_QEIEnable(QEI1_BASE);
	}
#endif



}
/*
#ifdef USEQEI0
void ManejadorQEI0(){
	//Ha llegado al limite, por lo que se ha movido 2pi radianes

	if(QEI_INTTIMER == 	QEIIntStatus(QEI0_BASE,1)){ //Limpiamos la interrupcion
	float temp = Enc0Rad;
	if(QEIDirectionGet(QEI0_BASE)){
		temp = temp + 2* M_PI;
	}else{
		temp = temp - 2* M_PI;
	}
	Enc0Rad = temp;
	}
	QEIIntClear(QEI0_BASE,QEIIntStatus(QEI0_BASE,1));


}
#endif
#ifdef USEQEI1
void ManejadorQEI1(){
	//Ha llegado al limite, por lo que se ha movido 2pi radianes
	if(QEI_INTTIMER == QEIIntStatus(QEI1_BASE,1)){
	float temp1 = Enc1Rad;
	if(QEIDirectionGet(QEI1_BASE)){
		temp1 = temp1 + 2* M_PI;
	}else{
		temp1 = temp1 - 2* M_PI;
	}
	Enc1Rad = temp1;
	}
	QEIIntClear(QEI1_BASE,QEIIntStatus(QEI1_BASE,1));
}
#endif
*/

//Devuelve el numero de vueltas en radianes

float QeiRotacionEncoder(uint8_t enc){
	float temp = 0.0;
#ifdef USEQEI0
	if(enc == QEI0){
	temp = (float) (ROM_QEIPositionGet(QEI0_BASE) *2* M_PI)/PulsosEncoder0;

	}
#endif
#ifdef USEQEI1
	if(enc == QEI1){
	 temp = (float) (ROM_QEIPositionGet(QEI1_BASE) *2* M_PI)/PulsosEncoder1;
	}

#endif
return temp;
}


