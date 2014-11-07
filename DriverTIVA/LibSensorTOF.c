/*  LibSensorTOF.c
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


#include "LibSensorTOF.h"
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "Funciones.h"
#include "Configuration.h"
#include "driverlib/interrupt.h"

static GPIO ConfigGPIO;
static uint32_t Mask[6] = {0,0,0,0,0,0};

#ifdef USEPORTA
static uint64_t ValorA[8];
#endif
#ifdef USEPORTB
static uint64_t ValorB[8];
#endif
#ifdef USEPORTC
static uint64_t ValorC[8];
#endif
#ifdef USEPORTD
static uint64_t ValorD[8];
#endif
#ifdef USEPORTE
static uint64_t ValorE[8];
#endif
#ifdef USEPORTF
static uint64_t ValorF[8];
#endif
#ifdef USEPORTA
 static  float ValorAResultado[8];
#endif
#ifdef USEPORTB
static  float ValorBResultado[8];
#endif
#ifdef USEPORTC
static  float ValorCResultado[8];
#endif
#ifdef USEPORTD
static  float ValorDResultado[8];
#endif
#ifdef USEPORTE
static  float ValorEResultado[8];
#endif
#ifdef USEPORTF
static  float ValorFResultado[8];
#endif


float SensorPuertoPin(uint8_t pin){
	 uint8_t temp = pin%8;
	 uint8_t temp2 = pin/8;
	 float tempvalor = 0.0;
	 switch(temp2){

	 case 0:{
		#ifdef USEPORTA
		 tempvalor = ValorAResultado[temp];
		#endif
	 }break;
	 case 1:{
		#ifdef USEPORTB
		 tempvalor = ValorBResultado[temp];
		#endif
	 }break;
	 case 2:{
		#ifdef USEPORTC
		 tempvalor = ValorCResultado[temp];
		#endif
	 }break;
	 case 3:{
		#ifdef USEPORTD
		 tempvalor = ValorDResultado[temp];
		#endif
	 }break;
	 case 4:{
		#ifdef USEPORTE
		 tempvalor = ValorEResultado[temp];
		#endif
	 }break;
	 case 5:{
		#ifdef USEPORTF
		 tempvalor = ValorFResultado[temp];
		#endif
	 }break;
	 default:break;

	 }
	 return tempvalor;

}



//Interrupción cuando pasan los 10us
void HandleTrigger(){

	TimerIntClear(TIMER1_BASE,TIMER_TIMA_TIMEOUT);
	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3,0);
	TimerIntUnregister(TIMER1_BASE,TIMER_A);
	TimerDisable(TIMER1_BASE,TIMER_A);

}



void TOFTrigger(){

	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);

	TimerDisable(TIMER1_BASE,TIMER_A);
	uint32_t frecCTL = SysCtlClockGet();
	int32_t tick4us = (int32_t ) (frecCTL * 10e-6);
	TimerConfigure(TIMER1_BASE,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_ONE_SHOT);
	TimerLoadSet(TIMER1_BASE,TIMER_A,tick4us);
	TimerMatchSet(TIMER1_BASE,TIMER_A,0);
	TimerIntRegister(TIMER1_BASE,TIMER_A,HandleTrigger );
	TimerIntEnable(TIMER1_BASE,TIMER_TIMA_TIMEOUT);
	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3,GPIO_PIN_3);
	TimerEnable(TIMER1_BASE,TIMER_A);

}



void TOFEchoInit(uint8_t GPIOPin)
{
    //
    // Enable Peripheral Clocks
    //
#ifdef USEPORTA
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    MAP_SysCtlDelay(3);
#endif
#ifdef USEPORTB
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    MAP_SysCtlDelay(3);
#endif
#ifdef USEPORTC
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    MAP_SysCtlDelay(3);
#endif
#ifdef USEPORTD
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    MAP_SysCtlDelay(3);
#endif
#ifdef USEPORTE
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    MAP_SysCtlDelay(3);
#endif
#ifdef USEPORTF
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    MAP_SysCtlDelay(3);
#endif

    switch(GPIOPin){
#ifdef USEPORTA
	//Puerto A
#ifdef USEPORTAPIN0
    case PA0:{
    	if(!ConfigGPIO.GPIOS.PoA0){
		//
		// Enable pin PA0 for GPIOInput
		//
    	ConfigGPIO.GPIOS.PoA0 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_0);
		GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		Mask[0] += GPIO_INT_PIN_0;
    	}
		break;
    }
#endif
#ifdef USEPORTAPIN1
    case PA1:{
    	if(!ConfigGPIO.GPIOS.PoA1){
		//
		// Enable pin PA1 for GPIOInput
		//
    	ConfigGPIO.GPIOS.PoA1 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_1);
		GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		Mask[0] += GPIO_INT_PIN_1;
    	}
		break;
    }
#endif
#ifdef USEPORTAPIN2
    case PA2:{
    	if(!ConfigGPIO.GPIOS.PoA2){
    	//
		// Enable pin PA2 for GPIOInput
		//
    	ConfigGPIO.GPIOS.PoA2 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_2);
		GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		Mask[0] += GPIO_INT_PIN_2;
    	}
		break;
    }
#endif
#ifdef USEPORTAPIN3
    case PA3:{
    	if(!ConfigGPIO.GPIOS.PoA3){
    	//
		// Enable pin PA3 for GPIOInput
		//
        ConfigGPIO.GPIOS.PoA3 = 1;
		GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_3);
		GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		Mask[0] += GPIO_INT_PIN_3;
    	}
		break;
	}
#endif
#ifdef USEPORTAPIN4
	case PA4:{
		if(!ConfigGPIO.GPIOS.PoA4){
		//
		// Enable pin PA4 for GPIOInput
		//
	    ConfigGPIO.GPIOS.PoA4 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_4);
		GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		Mask[0] += GPIO_INT_PIN_4;
		}
		break;
	}
#endif
#ifdef USEPORTAPIN5
	case PA5:{
		if(!ConfigGPIO.GPIOS.PoA5){
		//
		// Enable pin PA5 for GPIOInput
		//
	    ConfigGPIO.GPIOS.PoA5 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_5);
		GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		Mask[0] += GPIO_INT_PIN_5;
		}
		break;
	}
#endif
#ifdef USEPORTAPIN6
	case PA6:{
		if(!ConfigGPIO.GPIOS.PoA6){
		//
		// Enable pin PA6 for GPIOInput
		//
	    ConfigGPIO.GPIOS.PoA6 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_6);
		GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		Mask[0] += GPIO_INT_PIN_6;
		}
		break;
	}
#endif
#ifdef USEPORTAPIN7
	case PA7:{
		if(!ConfigGPIO.GPIOS.PoA7){
		//
		// Enable pin PA7 for GPIOInput
		//
		ConfigGPIO.GPIOS.PoA7 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_7);
		GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		Mask[0] += GPIO_INT_PIN_7;
		}
		break;
	}
#endif
#endif
#ifdef USEPORTB
	//Puerto B
#ifdef USEPORTBPIN0
	case PB0:{
		if(!ConfigGPIO.GPIOS.PoB0){
		//
		// Enable pin PB0 for GPIOInput
		//
		ConfigGPIO.GPIOS.PoB0 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_0);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		Mask[1] += GPIO_INT_PIN_0;
		}
		break;
	}
#endif
#ifdef USEPORTBPIN1
	case PB1:{
		if(!ConfigGPIO.GPIOS.PoB1){
		//
		// Enable pin PB1 for GPIOInput
		//
		ConfigGPIO.GPIOS.PoB1 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_1);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		Mask[1] += GPIO_INT_PIN_0;
		}
		break;
	}
#endif
#ifdef USEPORTBPIN2
	case PB2:{
		if(!ConfigGPIO.GPIOS.PoB2){
		//
		// Enable pin PB2 for GPIOInput
		//
		ConfigGPIO.GPIOS.PoB2 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_2);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		Mask[1] += GPIO_INT_PIN_2;
		}
		break;
	}
#endif
#ifdef USEPORTBPIN3
	case PB3:{
		if(!ConfigGPIO.GPIOS.PoB3){
		//
		// Enable pin PB3 for GPIOInput
		//
		ConfigGPIO.GPIOS.PoB3 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_3);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_3,GPIO_RISING_EDGE  );
		Mask[1] += GPIO_INT_PIN_3;
		}
		break;
	}
#endif
#ifdef USEPORTBPIN4
	case PB4:{
		if(!ConfigGPIO.GPIOS.PoB4){
		//
		// Enable pin PB4 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoB4 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_4);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		Mask[1] += GPIO_INT_PIN_4;
		}
		break;
	}
#endif
#ifdef USEPORTBPIN5
	case PB5:{
		if(!ConfigGPIO.GPIOS.PoB5){
		//
		// Enable pin PB5 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoB5 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_5);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		Mask[1] += GPIO_INT_PIN_5;
		}
		break;
	}
#endif
#ifdef USEPORTBPIN6
	case PB6:{
		if(!ConfigGPIO.GPIOS.PoB6){
		//
		// Enable pin PB6 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoB6 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_6);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		Mask[1] += GPIO_INT_PIN_6;
		}
		break;
	}
#endif
#ifdef USEPORTBPIN7
	case PB7:{
		if(!ConfigGPIO.GPIOS.PoB7){
		//
		// Enable pin PB7 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoB7 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_7);
		GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		Mask[1] += GPIO_INT_PIN_7;
		}
			break;
		}
#endif
#endif
#ifdef USEPORTC
	//Puerto C
#ifdef USEPORTCPIN4
	case PC4:{
		if(!ConfigGPIO.GPIOS.PoC4){
		//
		// Enable pin PC4 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoC4 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_4);
		GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		Mask[2] += GPIO_INT_PIN_4;
		}
		break;
	}
#endif
#ifdef USEPORTCPIN5
	case PC5:{
		if(!ConfigGPIO.GPIOS.PoC5){
		//
		// Enable pin PC5 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoC5 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_5);
		GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		Mask[2] += GPIO_INT_PIN_5;
		}
		break;
	}
#endif
#ifdef USEPORTCPIN6
	case PC6:{
		if(!ConfigGPIO.GPIOS.PoC6){
		//
		// Enable pin PC6 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoC6 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_6);
		GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		Mask[2] += GPIO_INT_PIN_6;
		}
		break;
	}
#endif
#ifdef USEPORTCPIN7
	case PC7:{
		if(!ConfigGPIO.GPIOS.PoC7){
		//
		// Enable pin PC7 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoC7 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_7);
		GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		Mask[2] += GPIO_INT_PIN_7;
		}
		break;
	}
#endif
#endif
#ifdef USEPORTD
	//Puerto D
#ifdef USEPORTDPIN0
	case PD0:{
		if(!ConfigGPIO.GPIOS.PoD0){
		//
		// Enable pin PD0 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoD0 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_0);
		GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		Mask[3] += GPIO_INT_PIN_0;
		}
		break;
	}
#endif
#ifdef USEPORTDPIN1
	case PD1:{
		if(!ConfigGPIO.GPIOS.PoD1){
		//
		// Enable pin PD1 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoD1 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_1);
		GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		Mask[3] += GPIO_INT_PIN_1;
		}
		break;
	}
#endif
#ifdef USEPORTDPIN2
	case PD2:{
		if(!ConfigGPIO.GPIOS.PoD2){
		//
		// Enable pin PD2 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoD2 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_2);
		GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		Mask[3] += GPIO_INT_PIN_2;
		}
		break;
	}
#endif
#ifdef USEPORTDPIN3
	case PD3:{
		if(!ConfigGPIO.GPIOS.PoD3){
		//
		// Enable pin PD3 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoD3 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_3);
		GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		Mask[3] += GPIO_INT_PIN_3;
		}
		break;
	}
#endif
#ifdef USEPORTDPIN4
	case PD4:{
		if(!ConfigGPIO.GPIOS.PoD4){
		//
		// Enable pin PD4 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoD4 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_4);
		GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		Mask[3] += GPIO_INT_PIN_4;
		}
		break;
	}
#endif
#ifdef USEPORTDPIN5
	case PD5:{
		if(!ConfigGPIO.GPIOS.PoD5){
		//
		// Enable pin PD5 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoD5 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_5);
		GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		Mask[3] += GPIO_INT_PIN_5;
		}
		break;
	}
#endif
#ifdef USEPORTDPIN6
	case PD6:{
		if(!ConfigGPIO.GPIOS.PoD6){
		//
		// Enable pin PD6 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoD6 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_6);
		GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		Mask[3] += GPIO_INT_PIN_6;
		}
		break;
	}
#endif
#ifdef USEPORTDPIN7
	case PD7:{
		if(!ConfigGPIO.GPIOS.PoD7){
		//
		// Enable pin PD7 for GPIOInput
		//

		//
		//First open the lock and select the bits we want to modify in the GPIO commit register.
		//
		HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
		HWREG(GPIO_PORTD_BASE + GPIO_O_CR) = 0x80;

		//
		//Now modify the configuration of the pins that we unlocked.
		//
		ConfigGPIO.GPIOS.PoD7 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_7);
		GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		Mask[3] += GPIO_INT_PIN_7;
		}
		break;
	}
#endif
#endif
#ifdef USEPORTE
	//Puerto E
#ifdef USEPORTEPIN0
	case PE0:{
		if(!ConfigGPIO.GPIOS.PoE0){
		//
		// Enable pin PE0 for GPIOInput
		//
		ConfigGPIO.GPIOS.PoE0 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_0);
		GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		Mask[4] += GPIO_INT_PIN_0;
		}
		break;
	}
#endif
#ifdef USEPORTEPIN1
	case PE1:{
		if(!ConfigGPIO.GPIOS.PoE1){
		//
		// Enable pin PE1 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoE1 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_1);
		GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		Mask[4] += GPIO_INT_PIN_1;
		}
		break;
	}
#endif
#ifdef USEPORTEPIN2
	case PE2:{
		if(!ConfigGPIO.GPIOS.PoE2){
		//
		// Enable pin PE2 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoE2 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_2);
		GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		Mask[4] += GPIO_INT_PIN_2;
		}

		//	break;
	}
#endif
#ifdef USEPORTEPIN3
	case PE3:{
		if(!ConfigGPIO.GPIOS.PoE3){
		// Enable pin PE3 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoE3 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_3);
		GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		Mask[4] += GPIO_INT_PIN_3;
		}
		break;
	}
#endif
#ifdef USEPORTEPIN4
	case PE4:{
		if(!ConfigGPIO.GPIOS.PoE4){
		//
		// Enable pin PE4 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoE4 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_4);
		GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		Mask[4] += GPIO_INT_PIN_4;
		}
		break;
	}
#endif
#ifdef USEPORTEPIN5
	case PE5:{
		if(!ConfigGPIO.GPIOS.PoE5){
		//
		// Enable pin PE5 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoE5 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_5);
		GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		Mask[4] += GPIO_INT_PIN_5;
		}
		break;
	}
#endif
#endif
#ifdef USEPORTF
	//Puerto F
#ifdef USEPORTFPIN0
	case PF0:{
		if(!ConfigGPIO.GPIOS.PoF0){
		//
		// Enable pin PF0 for GPIOInput
		//

		//
		//First open the lock and select the bits we want to modify in the GPIO commit register.
		//
		HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
		HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0x1;

		//
		//Now modify the configuration of the pins that we unlocked.
		//
		ConfigGPIO.GPIOS.PoF0 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
		GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		Mask[5] += GPIO_INT_PIN_0;
		}
		break;
	}
#endif
#ifdef USEPORTFPIN1
	case PF1:{
		if(!ConfigGPIO.GPIOS.PoF1){
		//
		// Enable pin PF1 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoF1 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_1);
		GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		Mask[5] += GPIO_INT_PIN_1;
		}
		break;
	}
#endif
#ifdef USEPORTFPIN2
	case PF2:{
		if(!ConfigGPIO.GPIOS.PoF2){
		//
		// Enable pin PF2 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoF2 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_2);
		GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		Mask[5] += GPIO_INT_PIN_2;
		}
		break;
	}
#endif
#ifdef USEPORTFPIN3
	case PF3:{
		if(!ConfigGPIO.GPIOS.PoF3){
		//
		// Enable pin PF3 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoF3 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_3);
		GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		Mask[5] += GPIO_INT_PIN_3;
		}
		break;
	}
#endif
#ifdef USEPORTFPIN4
	case PF4:{
		if(!ConfigGPIO.GPIOS.PoF4){
		//
		// Enable pin PF4 for GPIOInput
		//
			ConfigGPIO.GPIOS.PoF4 = 1;
		MAP_GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
		GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		Mask[5] += GPIO_INT_PIN_4;
		}
		break;
	}
#endif
#endif
	default: break;

    }
	GPIOIntClear(GPIO_PORTA_BASE,0x0F);
	GPIOIntClear(GPIO_PORTB_BASE,0x0F);
	GPIOIntClear(GPIO_PORTC_BASE,0x0F);
	GPIOIntClear(GPIO_PORTD_BASE,0x0F);
	GPIOIntClear(GPIO_PORTE_BASE,0x0F);
	GPIOIntClear(GPIO_PORTF_BASE,0x0F);
	GPIOIntDisable(GPIO_PORTA_BASE,0x0F);
	GPIOIntDisable(GPIO_PORTB_BASE,0x0F);
	GPIOIntDisable(GPIO_PORTC_BASE,0x0F);
	GPIOIntDisable(GPIO_PORTD_BASE,0x0F);
	GPIOIntDisable(GPIO_PORTE_BASE,0x0F);
	GPIOIntDisable(GPIO_PORTF_BASE,0x0F);

#ifdef USEPORTA
	//Habilitacion de las interrupciones:
	//Puerto A con algo configurado
	if(ConfigGPIO.PortGpio[0] >0){

		//Primero deshabilita configura habilita
		 //IntEnable(INT_GPIOA);
		GPIOIntEnable(GPIO_PORTA_BASE,Mask[0]);
		//GPIOPadConfigSet(GPIO_PORTA_BASE,Mask[0],GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
		GPIOIntRegister(GPIO_PORTA_BASE,TOFProcess);
		//GPIOIntTypeSet(GPIO_PORTA_BASE,Mask[0],GPIO_RISING_EDGE);


	}
#endif

#ifdef USEPORTB
	//Puerto B con algo configurado
	if(ConfigGPIO.PortGpio[1] >0){
	//	GPIOIntTypeSet(GPIO_PORTB_BASE,Mask[1],GPIO_PIN_TYPE_STD_WPD);
		GPIOIntRegister(GPIO_PORTB_BASE,TOFProcess);
		GPIOIntEnable(GPIO_PORTB_BASE,Mask[1]);

	}
#endif
#ifdef USEPORTC
	//Puerto C con algo configurado
	if(ConfigGPIO.PortGpio[2] >0){
		GPIOIntEnable(GPIO_PORTC_BASE,Mask[2]);
		GPIOIntRegister(GPIO_PORTC_BASE,TOFProcess);
	}
#endif
#ifdef USEPORTD
	//Puerto D con algo configurado
	if(ConfigGPIO.PortGpio[3] >0){
		GPIOIntEnable(GPIO_PORTD_BASE,Mask[3]);
		GPIOIntRegister(GPIO_PORTD_BASE,TOFProcess);
	}
#endif
#ifdef USEPORTE
	//Puerto E con algo configurado
	if(ConfigGPIO.PortGpio[4] >0){
		GPIOIntEnable(GPIO_PORTE_BASE,Mask[4]);
		GPIOIntRegister(GPIO_PORTE_BASE,TOFProcess);
	}
#endif
#ifdef USEPORTF
	//Puerto F con algo configurado
	if(ConfigGPIO.PortGpio[5] >0){
		GPIOIntEnable(GPIO_PORTF_BASE,Mask[5]);
		GPIOIntRegister(GPIO_PORTF_BASE,TOFProcess);
	}
#endif
	IntMasterEnable();



}

	//En esta funcion, se realiza lo siguiente:
	//Primero saltará cuando llegue el puslo de llegada positivo, entonces se recogerá el valor para
	//ese pin del timer, y se cambiará el tipo de interrupcion por flanco de bajada.
	//dado esto podremos hacer la conversión
	//a cm dado que los cm son us/58
	//Al finalizar se debe volver a cambiar el tipo de interrupcion por flanco de subida


void TOFProcess(){
//#ifdef USEPORTA || USEPORTB || USEPORTC || USEPORTD || USEPORTE || USEPORTF

	//nada mas llegar nos da igual que pin sea,
	uint64_t temporal = micros();
	//Ahora aqui revisamos las interrupciones y deducimos el puerto en cuestion y su pin
	int32_t interrupts;

//#endif

#ifdef USEPORTA
	interrupts =  GPIOIntStatus(GPIO_PORTA_BASE,true);
#ifdef USEPORTAPIN0
	if(interrupts &&GPIO_INT_PIN_0 ){
		if(GPIOIntTypeGet(GPIO_PORTA_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorA[0] = temporal;
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorAResultado[0] =  ((float)(temporal / ValorA[0])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTAPIN1
	interrupts = Mask[1];
	if((interrupts &&GPIO_INT_PIN_1) >>1 ){
		if(GPIOIntTypeGet(GPIO_PORTA_BASE,GPIO_PIN_1) == GPIO_HIGH_LEVEL){
			ValorA[1] = temporal;
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_1,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorAResultado[0] =  ((float)(temporal / ValorA[1])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTAPIN2
	if((interrupts &&GPIO_INT_PIN_2) >>2 ){
		if(GPIOIntTypeGet(GPIO_PORTA_BASE,GPIO_PIN_2) == GPIO_HIGH_LEVEL){
			ValorA[2] = temporal;
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorAResultado[2] =  ((float)(temporal / ValorA[2])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTAPIN3
	if((interrupts &&GPIO_INT_PIN_3) >>3 ){
		if(GPIOIntTypeGet(GPIO_PORTA_BASE,GPIO_PIN_3) == GPIO_HIGH_LEVEL){
			ValorA[3] = temporal;
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_3,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorAResultado[3] =  ((float)(temporal / ValorA[3])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);

		}
	}
#endif
#ifdef USEPORTAPIN4
	if((interrupts &&GPIO_INT_PIN_4) >>4 ){
		if(GPIOIntTypeGet(GPIO_PORTA_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorA[4] = temporal;
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorAResultado[4] =  ((float)(temporal / ValorA[4])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTAPIN5
	if((interrupts &&GPIO_INT_PIN_5) >>5 ){
		if(GPIOIntTypeGet(GPIO_PORTA_BASE,GPIO_PIN_5) == GPIO_HIGH_LEVEL){
			ValorA[5] = temporal;
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_5,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorAResultado[5] =  ((float)(temporal / ValorA[5])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTAPIN6
	if((interrupts &&GPIO_INT_PIN_6) >>6 ){
		if(GPIOIntTypeGet(GPIO_PORTA_BASE,GPIO_PIN_6) == GPIO_HIGH_LEVEL){
			ValorA[6] = temporal;
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_6,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorAResultado[6] =  ((float)(temporal / ValorA[6])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTAPIN7
	if((interrupts &&GPIO_INT_PIN_7) >>7 ){
		if(GPIOIntTypeGet(GPIO_PORTA_BASE,GPIO_PIN_7) == GPIO_HIGH_LEVEL){
			ValorA[7] = temporal;
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_7,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorAResultado[7] =  ((float)(temporal / ValorA[7])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		}
	}
#endif
	//Limpiamos las interrupciones antes de salir
	GPIOIntClear(GPIO_PORTA_BASE,interrupts);
#endif
#ifdef USEPORTB
	interrupts = 0;
	interrupts=  GPIOIntStatus(GPIO_PORTB_BASE,true);
#ifdef USEPORTBPIN0
	if(interrupts &&GPIO_INT_PIN_0 ){
		if(GPIOIntTypeGet(GPIO_PORTB_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorB[0] = temporal;
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorBResultado[0] =  ((float)(temporal / ValorB[0])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTBPIN1
	if((interrupts &&GPIO_INT_PIN_1) >>1 ){
		if(GPIOIntTypeGet(GPIO_PORTB_BASE,GPIO_PIN_1) == GPIO_HIGH_LEVEL){
			ValorB[1] = temporal;
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorBResultado[0] =  ((float)(temporal / ValorB[1])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTBPIN2
	if((interrupts &&GPIO_INT_PIN_2) >>2 ){
		if(GPIOIntTypeGet(GPIO_PORTB_BASE,GPIO_PIN_2) == GPIO_HIGH_LEVEL){
			ValorB[2] = temporal;
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_2,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorBResultado[2] =  ((float)(temporal / ValorB[2])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTBPIN3
	if((interrupts &&GPIO_INT_PIN_3) >>3 ){
		if(GPIOIntTypeGet(GPIO_PORTB_BASE,GPIO_PIN_3) == GPIO_HIGH_LEVEL){
			ValorB[3] = temporal;
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_3,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorBResultado[3] =  ((float)(temporal / ValorB[3])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTBPIN4
	if((interrupts &&GPIO_INT_PIN_4) >>4 ){
		if(GPIOIntTypeGet(GPIO_PORTB_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorB[4] = temporal;
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorBResultado[4] =  ((float)(temporal / ValorB[4])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTBPIN5
	if((interrupts &&GPIO_INT_PIN_5) >>5 ){
		if(GPIOIntTypeGet(GPIO_PORTB_BASE,GPIO_PIN_5) == GPIO_HIGH_LEVEL){
			ValorB[5] = temporal;
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_5,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorBResultado[5] =  ((float)(temporal / ValorB[5])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTBPIN6
	if((interrupts &&GPIO_INT_PIN_6) >>6 ){
		if(GPIOIntTypeGet(GPIO_PORTB_BASE,GPIO_PIN_6) == GPIO_HIGH_LEVEL){
			ValorB[6] = temporal;
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_6,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorBResultado[6] =  ((float)(temporal / ValorB[6])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTBPIN7
	if((interrupts &&GPIO_INT_PIN_7) >>7 ){
		if(GPIOIntTypeGet(GPIO_PORTB_BASE,GPIO_PIN_7) == GPIO_HIGH_LEVEL){
			ValorB[7] = temporal;
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_7,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorBResultado[7] =  ((float)(temporal / ValorB[7])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		}
	}
#endif
GPIOIntClear(GPIO_PORTB_BASE,interrupts);
#endif
#ifdef USEPORTC
	interrupts = 0;
	interrupts=  GPIOIntStatus(GPIO_PORTC_BASE,true);
/*
 * Estos pines no son validos
	if(interrupts &&GPIO_INT_PIN_0 ){
		if(GPIOIntTypeGet(GPIO_PORTC_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorC[0] = temporal;
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorCResultado[0] =  ((float)(temporal / ValorC[0])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		}
	}
	if((interrupts &&GPIO_INT_PIN_1) >>1 ){
		if(GPIOIntTypeGet(GPIO_PORTC_BASE,GPIO_PIN_1) == GPIO_HIGH_LEVEL){
			ValorC[1] = temporal;
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_1,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorCResultado[0] =  ((float)(temporal / ValorC[1])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		}
	}
	if((interrupts &&GPIO_INT_PIN_2) >>2 ){
		if(GPIOIntTypeGet(GPIO_PORTC_BASE,GPIO_PIN_2) == GPIO_HIGH_LEVEL){
			ValorC[2] = temporal;
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_2,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorCResultado[2] =  ((float)(temporal / ValorC[2])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		}
	}
	if((interrupts &&GPIO_INT_PIN_3) >>3 ){
		if(GPIOIntTypeGet(GPIO_PORTC_BASE,GPIO_PIN_3) == GPIO_HIGH_LEVEL){
			ValorC[3] = temporal;
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_3,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorCResultado[3] =  ((float)(temporal / ValorC[3])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		}
	}*/
#ifdef USEPORTCPIN4
	if((interrupts &&GPIO_INT_PIN_4) >>4 ){
		if(GPIOIntTypeGet(GPIO_PORTC_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorC[4] = temporal;
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorCResultado[4] =  ((float)(temporal / ValorC[4])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTCPIN5
	if((interrupts &&GPIO_INT_PIN_5) >>5 ){
		if(GPIOIntTypeGet(GPIO_PORTC_BASE,GPIO_PIN_5) == GPIO_HIGH_LEVEL){
			ValorC[5] = temporal;
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_5,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorCResultado[5] =  ((float)(temporal / ValorC[5])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTCPIN6
	if((interrupts &&GPIO_INT_PIN_6) >>6 ){
		if(GPIOIntTypeGet(GPIO_PORTC_BASE,GPIO_PIN_6) == GPIO_HIGH_LEVEL){
			ValorC[6] = temporal;
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_6,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorCResultado[6] =  ((float)(temporal / ValorC[6])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTCPIN7
	if((interrupts &&GPIO_INT_PIN_7) >>7 ){
		if(GPIOIntTypeGet(GPIO_PORTC_BASE,GPIO_PIN_7) == GPIO_HIGH_LEVEL){
			ValorC[7] = temporal;
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_7,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorCResultado[7] =  ((float)(temporal / ValorC[7])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTC_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		}
	}
#endif
GPIOIntClear(GPIO_PORTC_BASE,interrupts);
#endif
#ifdef USEPORTD
	interrupts = 0;
	interrupts=  GPIOIntStatus(GPIO_PORTD_BASE,true);
#ifdef USEPORTDPIN0
	if(interrupts &&GPIO_INT_PIN_0 ){
		if(GPIOIntTypeGet(GPIO_PORTD_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorD[0] = temporal;
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorDResultado[0] =  ((float)(temporal / ValorD[0])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTDPIN1
	if((interrupts &&GPIO_INT_PIN_1) >>1 ){
		if(GPIOIntTypeGet(GPIO_PORTD_BASE,GPIO_PIN_1) == GPIO_HIGH_LEVEL){
			ValorD[1] = temporal;
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_1,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorDResultado[0] =  ((float)(temporal / ValorD[1])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTDPIN2
	if((interrupts &&GPIO_INT_PIN_2) >>2 ){
		if(GPIOIntTypeGet(GPIO_PORTD_BASE,GPIO_PIN_2) == GPIO_HIGH_LEVEL){
			ValorD[2] = temporal;
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_2,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorDResultado[2] =  ((float)(temporal / ValorD[2])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTDPIN3
	if((interrupts &&GPIO_INT_PIN_3) >>3 ){
		if(GPIOIntTypeGet(GPIO_PORTD_BASE,GPIO_PIN_3) == GPIO_HIGH_LEVEL){
			ValorD[3] = temporal;
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_3,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorDResultado[3] =  ((float)(temporal / ValorD[3])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTDPIN4
	if((interrupts &&GPIO_INT_PIN_4) >>4 ){
		if(GPIOIntTypeGet(GPIO_PORTD_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorD[4] = temporal;
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorDResultado[4] =  ((float)(temporal / ValorD[4])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTDPIN5
	if((interrupts &&GPIO_INT_PIN_5) >>5 ){
		if(GPIOIntTypeGet(GPIO_PORTD_BASE,GPIO_PIN_5) == GPIO_HIGH_LEVEL){
			ValorD[5] = temporal;
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_5,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorDResultado[5] =  ((float)(temporal / ValorD[5])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTDPIN6
	if((interrupts &&GPIO_INT_PIN_6) >>6 ){
		if(GPIOIntTypeGet(GPIO_PORTD_BASE,GPIO_PIN_6) == GPIO_HIGH_LEVEL){
			ValorD[6] = temporal;
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_6,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorDResultado[6] =  ((float)(temporal / ValorD[6])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTDPIN7
	if((interrupts &&GPIO_INT_PIN_7) >>7 ){
		if(GPIOIntTypeGet(GPIO_PORTD_BASE,GPIO_PIN_7) == GPIO_HIGH_LEVEL){
			ValorD[7] = temporal;
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_7,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorDResultado[7] =  ((float)(temporal / ValorD[7])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		}
	}
#endif
GPIOIntClear(GPIO_PORTD_BASE,interrupts);
#endif
#ifdef USEPORTE
	interrupts = 0;
	interrupts=  GPIOIntStatus(GPIO_PORTE_BASE,true);
#ifdef USEPORTEPIN0
	if(interrupts &&GPIO_INT_PIN_0 ){
		if(GPIOIntTypeGet(GPIO_PORTE_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorE[0] = temporal;
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorEResultado[0] =  ((float)(temporal / ValorE[0])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTEPIN1
	if((interrupts &&GPIO_INT_PIN_1) >>1 ){
		if(GPIOIntTypeGet(GPIO_PORTE_BASE,GPIO_PIN_1) == GPIO_HIGH_LEVEL){
			ValorE[1] = temporal;
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorEResultado[0] =  ((float)(temporal / ValorE[1])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTEPIN2
	if((interrupts &&GPIO_INT_PIN_2) >>2 ){
		if(GPIOIntTypeGet(GPIO_PORTE_BASE,GPIO_PIN_2) == GPIO_HIGH_LEVEL){
			ValorE[2] = temporal;
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_2,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorEResultado[2] =  ((float)(temporal / ValorE[2])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTEPIN3
	if((interrupts &&GPIO_INT_PIN_3) >>3 ){
		if(GPIOIntTypeGet(GPIO_PORTE_BASE,GPIO_PIN_3) == GPIO_HIGH_LEVEL){
			ValorE[3] = temporal;
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_3,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorEResultado[3] =  ((float)(temporal / ValorE[3])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTEPIN4
	if((interrupts &&GPIO_INT_PIN_4) >>4 ){
		if(GPIOIntTypeGet(GPIO_PORTE_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorE[4] = temporal;
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorEResultado[4] =  ((float)(temporal / ValorE[4])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTEPIN5
	if((interrupts &&GPIO_INT_PIN_5) >>5 ){
		if(GPIOIntTypeGet(GPIO_PORTE_BASE,GPIO_PIN_5) == GPIO_HIGH_LEVEL){
			ValorE[5] = temporal;
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_5,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorEResultado[5] =  ((float)(temporal / ValorE[5])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		}
	}
#endif
	/*
	 * Estos pines no son validos
	if((interrupts &&GPIO_INT_PIN_6) >>6 ){
		if(GPIOIntTypeGet(GPIO_PORTE_BASE,GPIO_PIN_6) == GPIO_HIGH_LEVEL){
			ValorE[6] = temporal;
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_6,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorEResultado[6] =  ((float)(temporal / ValorE[6])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		}
	}
	if((interrupts &&GPIO_INT_PIN_7) >>7 ){
		if(GPIOIntTypeGet(GPIO_PORTE_BASE,GPIO_PIN_7) == GPIO_HIGH_LEVEL){
			ValorE[7] = temporal;
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_7,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorEResultado[7] =  ((float)(temporal / ValorE[7])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		}
	}*/
	GPIOIntClear(GPIO_PORTE_BASE,interrupts);
#endif
#ifdef USEPORTF
	interrupts = 0;
	interrupts=  GPIOIntStatus(GPIO_PORTF_BASE,true);
#ifdef USEPORTFPIN0
	if(interrupts &&GPIO_INT_PIN_0 ){
		if(GPIOIntTypeGet(GPIO_PORTF_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorF[0] = temporal;
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorFResultado[0] =  ((float)(temporal / ValorF[0])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTFPIN1
	if((interrupts &&GPIO_INT_PIN_1) >>1 ){
		if(GPIOIntTypeGet(GPIO_PORTF_BASE,GPIO_PIN_1) == GPIO_HIGH_LEVEL){
			ValorF[1] = temporal;
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorFResultado[0] =  ((float)(temporal / ValorF[1])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTFPIN2
	if((interrupts &&GPIO_INT_PIN_2) >>2 ){
		if(GPIOIntTypeGet(GPIO_PORTF_BASE,GPIO_PIN_2) == GPIO_HIGH_LEVEL){
			ValorF[2] = temporal;
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorFResultado[2] =  ((float)(temporal / ValorF[2])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTFPIN3
	if((interrupts &&GPIO_INT_PIN_3) >>3 ){
		if(GPIOIntTypeGet(GPIO_PORTF_BASE,GPIO_PIN_3) == GPIO_HIGH_LEVEL){
			ValorF[3] = temporal;
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_3,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorFResultado[3] =  ((float)(temporal / ValorF[3])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_3,GPIO_HIGH_LEVEL);
		}
	}
#endif
#ifdef USEPORTFPIN4
	if((interrupts &&GPIO_INT_PIN_4) >>4 ){
		if(GPIOIntTypeGet(GPIO_PORTF_BASE,GPIO_PIN_0) == GPIO_HIGH_LEVEL){
			ValorF[4] = temporal;
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorFResultado[4] =  ((float)(temporal / ValorF[4])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_HIGH_LEVEL);
		}
	}
#endif
	/*Estos Pines no son validos
	 * */
/*	if((interrupts &&GPIO_INT_PIN_5) >>5 ){
		if(GPIOIntTypeGet(GPIO_PORTF_BASE,GPIO_PIN_5) == GPIO_HIGH_LEVEL){
			ValorF[5] = temporal;
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_5,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorFResultado[5] =  ((float)(temporal / ValorF[5])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_5,GPIO_HIGH_LEVEL);
		}
	}
	if((interrupts &&GPIO_INT_PIN_6) >>6 ){
		if(GPIOIntTypeGet(GPIO_PORTF_BASE,GPIO_PIN_6) == GPIO_HIGH_LEVEL){
			ValorF[6] = temporal;
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_6,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorFResultado[6] =  ((float)(temporal / ValorF[6])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_6,GPIO_HIGH_LEVEL);
		}
	}
	if((interrupts &&GPIO_INT_PIN_7) >>7 ){
		if(GPIOIntTypeGet(GPIO_PORTF_BASE,GPIO_PIN_7) == GPIO_HIGH_LEVEL){
			ValorF[7] = temporal;
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_7,GPIO_LOW_LEVEL);
		}else{
			//Aqui es la bajada y ya podemos hacer la diferencia de tiempos para obtener el valor
			ValorFResultado[7] =  ((float)(temporal / ValorF[7])) / CteVuelo; //Resultado en cm
			GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_7,GPIO_HIGH_LEVEL);
		}
	}*/
	GPIOIntClear(GPIO_PORTF_BASE,interrupts);
#endif
}








