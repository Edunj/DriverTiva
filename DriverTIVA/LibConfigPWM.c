/*  LibConfigPWM.c
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
#include "LibConfigPWM.h"
#include <stdbool.h>
#include "math.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "driverlib/rom.h"
#include "Funciones.h"
#include "Configuration.h"



static PW ConfigPwm; // Pwm array, where a one mean a this Pwm is active, and zero is a Pwm desactive
static float Period ;
static float UstoTicks;
#

int initPWMS( int  periodMs ){

	WidthUs = periodMs*1000;

if(ROM_SysCtlClockGet() < 167777216  ){
	ROM_SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
	Period = (periodMs *ROM_SysCtlClockGet())/1000;
	Period = Period/64;
}else
{
	return -1;
}

UstoTicks = Period /WidthUs;


#ifdef USEGENPWM0
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
#endif
#ifdef USEGENPWM1
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
#endif

// Enable Peripheral GPIO
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
#
// Inicialization servos
#ifdef USEGENPWM0
ConfigPwm.PWMS[0] = 0x00;
#endif
#ifdef USEGENPWM1
ConfigPwm.PWMS[1] = 0x00;
#endif
return 0;
}




 void ConfigPWM(uint8_t pin,uint16_t min, uint16_t max ){


	 switch(pin){
#ifdef USEGENPWM0
#ifdef USEOUTPWM0
	    case PWM0:{
	    	// Enable pin PB6 for PWM0 M0PWM0 --> PWM0
	    	if(!ConfigPwm.PWM.PW0){
	    		ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW0 = 1;
				Min[0] = (uint16_t)(UstoTicks*min);
				Max[0] = (uint16_t)(UstoTicks*max);
				ROM_GPIOPinConfigure(GPIO_PB6_M0PWM0);
				ROM_GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);
				ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, (uint32_t)(Period));
				ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 0);
				ROM_PWMGenEnable(PWM0_BASE,PWM_GEN_0);
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
	    	}
			break;

	    }
#endif
#ifdef USEOUTPWM1
	    case PWM1:{
	    	// Enable pin PB7 for PWM0 M0PWM1 --> PWM1
	    	if(!ConfigPwm.PWM.PW1){
	    		ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_0,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	    		ConfigPwm.PWM.PW1 = 1;
	    		Min[1] = UstoTicks*min;
	    		Max[1] = UstoTicks*max;
	    		ROM_GPIOPinConfigure(GPIO_PB7_M0PWM1);
	    		ROM_GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);
	    		ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, (uint32_t)Period);
	    		ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 0);
	    		ROM_PWMGenEnable(PWM0_BASE,PWM_GEN_0);
	    		ROM_PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true);
	    	}
	    	break;
	    }
#endif
#ifdef USEOUTPWM2
	    case PWM2:{
	    	// Enable pin PB4 for PWM0 M0PWM2 --> PWM2
	    	if(!ConfigPwm.PWM.PW2){
	    		ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW2 = 1;
				Min[2] = UstoTicks*min;
				Max[2] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PB4_M0PWM2);
				ROM_GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4);
				ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 0);
				ROM_PWMGenEnable(PWM0_BASE,PWM_GEN_1);
				PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, true);
	    	}
			break;

	    }
#endif
#ifdef USEOUTPWM3
	    case PWM3:{
	    	// Enable pin PB5 for PWM0 M0PWM3 --> PWM3
	    	if(!ConfigPwm.PWM.PW3){
	    		ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_1,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	    		ConfigPwm.PWM.PW3 = 1;
	    		Min[3] = UstoTicks*min;
	    		Max[3] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PB5_M0PWM3);
				ROM_GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);
				ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, 0);
				ROM_PWMGenEnable(PWM0_BASE,PWM_GEN_1);
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT, true);
	    	}
			break;

	    }
#endif
#ifdef USEOUTPWM4
	    case PWM4:{
	    	// Enable pin PE4 for PWM0 M0PWM4 --> PWM4
	    	if(!ConfigPwm.PWM.PW4){
	    		ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	    		ConfigPwm.PWM.PW4 = 1;
	    		Min[4] = UstoTicks*min;
	    		Max[4] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PE4_M0PWM4);
				ROM_GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4);
				ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, 0);
				ROM_PWMGenEnable(PWM0_BASE,PWM_GEN_2);
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true);
	    	}
			break;
	    }
#endif
#ifdef USEOUTPWM5
	    case PWM5:{
	    	// Enable pin PE5 for PWM0 M0PWM5 --> PWM5
	    	if(!ConfigPwm.PWM.PW5){
	    		ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_2,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	    		ConfigPwm.PWM.PW5 = 1;
	    		Min[5] = UstoTicks*min;
	    		Max[5] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PE5_M0PWM5);
				ROM_GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5);
				ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 0);
				ROM_PWMGenEnable(PWM0_BASE,PWM_GEN_2);
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
	    	}
			break;
	    }
#endif
#ifdef USEOUTPWM6
	    case PWM6:{
	    	// Enable pin PC4 for PWM0 M0PWM6 --> PWM6
	    	if(!ConfigPwm.PWM.PW6){
	    		ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_3,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	    		ConfigPwm.PWM.PW6 = 1;
	    		Min[6] = UstoTicks*min;
	    		Max[6] = UstoTicks*max;
	    		ROM_GPIOPinConfigure(GPIO_PC4_M0PWM6);
	    		ROM_GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_4);
	    		ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, (uint32_t)Period);
	    		ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 0);
	    		ROM_PWMGenEnable(PWM0_BASE,PWM_GEN_3);
	    		ROM_PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, true);
	    	}
		   break;
	    }
#endif
#ifdef USEOUTPWM7
	    case PWM7:{
	    	// Enable pin PC5 for PWM0 M0PWM7 --> PWM7
	    	if(!ConfigPwm.PWM.PW7){
	    		ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_3,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	    		ConfigPwm.PWM.PW7 = 1;
	    		Min[7] = UstoTicks*min;
	    		Max[7] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PC5_M0PWM7);
				ROM_GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_5);
				ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_7, 0);
				ROM_PWMGenEnable(PWM0_BASE,PWM_GEN_3);
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, true);
	    	}
			break;
	    }
#endif

#endif
#ifdef USEGENPWM1
#ifdef USEOUTPWM8
	    case PWM8:{
	    	// Enable pin PD0 for PWM1 M1PWM0 --> PWM8
	    	if(!ConfigPwm.PWM.PW8){
	    		ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_0,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW8 = 1;
				Min[8] = UstoTicks*min;
				Max[8] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PD0_M1PWM0);
				ROM_GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);
				ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0);
				ROM_PWMGenEnable(PWM1_BASE,PWM_GEN_0);
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);

	    	}
		    break;

	    }
#endif
#ifdef USEOUTPWM9
	    case PWM9:{
	    	// Enable pin PD1 for PWM1 M1PWM1 --> PWM9
	    	if(!ConfigPwm.PWM.PW9){
	    		ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_0,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW9 = 1;
				Min[9] = UstoTicks*min;
				Max[9] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PD1_M1PWM1);
				ROM_GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1);
				ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0);
				ROM_PWMGenEnable(PWM1_BASE,PWM_GEN_0);
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, true);
	    	}
			break;
	    }
#endif
#ifdef USEOUTPWM10
	    case PWM10:{
	    	// Enable pin PA6 for PWM1 M1PWM2 --> PWM10
	    	if(!ConfigPwm.PWM.PW10){
	    		ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_1,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW10 = 1;
				Min[10] = UstoTicks*min;
				Max[10] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PA6_M1PWM2);
				ROM_GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6);
				ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0);
				ROM_PWMGenEnable(PWM1_BASE,PWM_GEN_1);
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true);

	    	}
			break;
	    }
#endif
#ifdef USEOUTPWM11
	    case PWM11:{
	    	// Enable pin PA7 for PWM1 M1PWM3 --> PWM11
	    	if(!ConfigPwm.PWM.PW11){
	    		ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW11 = 1;
				Min[11] = UstoTicks*min;
				Max[11] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PA7_M1PWM3);
				ROM_GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_7);
				ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0);
				ROM_PWMGenEnable(PWM1_BASE,PWM_GEN_1);
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, true);

	    	}
			break;
	    }
#endif
#ifdef USEOUTPWM12
	    case PWM12:{
	    	// Enable pin PF0 for PWM1 M1PWM4 --> PWM12
	    	if(!ConfigPwm.PWM.PW12){
	    		PWMGenConfigure(PWM1_BASE, PWM_GEN_2,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW12 = 1;
				Min[12] = UstoTicks*min;
				Max[12] = UstoTicks*max;
				// First open the lock and select the bits we want to modify in the GPIO commit register.
				HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
				HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0x1;
				// Now modify the configuration of the pins that we unlocked.
				ROM_GPIOPinConfigure(GPIO_PF0_M1PWM4);
				ROM_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0);
				ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_4, 0);
				ROM_PWMGenEnable(PWM1_BASE,PWM_GEN_2);
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_4_BIT, true);

	    	}
			break;
	    }
#endif
#ifdef USEOUTPWM13
	    case PWM13:{
	    	// Enable pin PF1 for PWM1 M1PWM5 --> PWM13
	    	if(!ConfigPwm.PWM.PW13){
	    		PWMGenConfigure(PWM1_BASE, PWM_GEN_2,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW13 = 1;
				Min[13] = UstoTicks*min;
				Max[13] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PF1_M1PWM5);
				ROM_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);
				ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, 0);
				ROM_PWMGenEnable(PWM1_BASE,PWM_GEN_2);
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, true);

	    	}
			break;
	    }
#endif
#ifdef USEOUTPWM14
	    //
	    case PWM14:{
		    // Enable pin PF2 for PWM1 M1PWM6 --> PWM14
	    	if(!ConfigPwm.PWM.PW14){
	    		ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_3,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW14 = 1;
				Min[14] = UstoTicks*min;
				Max[14] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PF2_M1PWM6);
				ROM_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);
				ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 0);
				ROM_PWMGenEnable(PWM1_BASE,PWM_GEN_3);
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, true);

	    	}
			break;
	    }
#endif
#ifdef USEOUTPWM15
	    case PWM15:{
	    	// Enable pin PF3 for PWM1 M1PWM7 --> PWM15
	    	if(!ConfigPwm.PWM.PW15){
	    		ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_3,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
				ConfigPwm.PWM.PW15 = 1;
				Min[15] = UstoTicks*min;
				Max[15] = UstoTicks*max;
				ROM_GPIOPinConfigure(GPIO_PF3_M1PWM7);
				ROM_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_3);
				ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, (uint32_t)Period);
				ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, 0);
				ROM_PWMGenEnable(PWM1_BASE,PWM_GEN_3);
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT, true);

	    	}
	    	break;
	    }
#endif

#endif
	     default:	{
	    	break;
	     }
	 }
 }






void TurnOffPWM(uint8_t pin){


switch(pin){
#ifdef USEGENPWM0

#ifdef USEOUTPWM0
	    	case PWM0:{
	    		ROM_PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, false);
				ConfigPwm.PWM.PW0 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM1
			case PWM1:{
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, false);
				ConfigPwm.PWM.PW1 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM2
			case PWM2:{
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, false);
				ConfigPwm.PWM.PW2 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM3
			case PWM3:{
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT, false);
				ConfigPwm.PWM.PW3 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM4
			case PWM4:{
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, false);
				ConfigPwm.PWM.PW4 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM5
			case PWM5:{
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, false);
				ConfigPwm.PWM.PW5 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM6
			case PWM6:{
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, false);
				ConfigPwm.PWM.PW6 = 0;
				 break;
			}
#endif
#ifdef USEOUTPWM7
			case PWM7:{
				ROM_PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, false);
				ConfigPwm.PWM.PW7 = 0;
				break;
			}
#endif
#endif
#ifdef USEGENPWM1

#ifdef USEOUTPWM8
			case PWM8:{
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, false);
				ConfigPwm.PWM.PW8 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM9
			case PWM9:{
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, false);
				ConfigPwm.PWM.PW9 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM10
			case PWM10:{
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, false);
				ConfigPwm.PWM.PW10 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM11
			case PWM11:{
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, false);
				ConfigPwm.PWM.PW11 = 0;
				 break;
			}
#endif
#ifdef USEOUTPWM12
			case PWM12:{
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_4_BIT, false);
				ConfigPwm.PWM.PW12 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM13
			case PWM13:{
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, false);
				ConfigPwm.PWM.PW13 = 0;
				 break;
			}
#endif
#ifdef USEOUTPWM14
			case PWM14:{
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, false);
				ConfigPwm.PWM.PW14 = 0;
				break;
			}
#endif
#ifdef USEOUTPWM15
			case PWM15:{
				ROM_PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT, false);
				ConfigPwm.PWM.PW15 = 0;
			  break;
			}
#endif
#endif
			 default:
				 break;
		 }
}



