/*  LibConfigADC.c
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

#include "LibConfigADC.h"
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_adc.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"
#include "driverlib/rom.h"
#include "Configuration.h"

#ifdef USEADC0
static AD ConfigAdc;
#endif

void InitSensorADC(void){
#ifdef USEADC0
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
#ifdef USEADC0SEQ0
	ROM_ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
#endif
#ifdef USEADC0SEQ1
	ROM_ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
#endif
 ADCHardwareOversampleConfigure(ADC0_BASE,64);

//Configuracion por defecto para todos los secuenciadores
#ifdef USEADC0SEQ0
	ROM_ADCSequenceStepConfigure(ADC0_BASE,0,0,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,0,1,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,0,2,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,0,3,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,0,4,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,0,5,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,0,6,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,0,7,ADC_CTL_TS|ADC_CTL_END|ADC_CTL_IE);
#endif
#ifdef USEADC0SEQ1
	ROM_ADCSequenceStepConfigure(ADC0_BASE,1,0,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,1,1,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,1,2,ADC_CTL_TS|ADC_CTL_IE);
	ROM_ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_TS|ADC_CTL_END|ADC_CTL_IE);
#endif


//Comprobacion de la configuracion de los puertos gpio
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
#endif
}




void ConfigSensorADC(int8_t Sensor){
#ifdef USEADC0
#ifdef USEADC0SEQ0
	ROM_ADCSequenceDisable(ADC0_BASE,0);
#endif
#ifdef USEADC0SEQ1
	ROM_ADCSequenceDisable(ADC0_BASE,1);
#endif

switch(Sensor){
#ifdef USEADC0SEQ0
#ifdef USEADC0SEQ0IN0
	    case ADC0:{
	    	if(!ConfigAdc.ADC.AD0){

	    	 //
			// Enable pin PE3 for ADC AIN0
			//
	    		ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,0,0,ADC_CTL_CH0|ADC_CTL_IE);
			ConfigAdc.ADC.AD0 = 1;
	    	}
	    	break;
	    }
#endif
#ifdef USEADC0SEQ0IN1

	    case ADC1:{
	    	if(!ConfigAdc.ADC.AD1){
	        //
	    	// Enable pin PE2 for ADC AIN1
	    	//
	    		ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_2);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,0,1,ADC_CTL_CH1|ADC_CTL_IE);
	    	ConfigAdc.ADC.AD1 = 1;
	    	}
	   	    	break;
	    }
#endif
#ifdef USEADC0SEQ0IN2
	    case ADC2:{
	    	if(!ConfigAdc.ADC.AD2){

	        //
	        // Enable pin PE1 for ADC AIN2
	        //
	    		ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_1);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,0,2,ADC_CTL_CH2|ADC_CTL_IE);
	        ConfigAdc.ADC.AD2 = 1;
	    	 }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN3
	    case ADC3:{
	    	if(!ConfigAdc.ADC.AD3){

	    	//
	        // Enable pin PE0 for ADC AIN3
	        //
	    		ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_0);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,0,3,ADC_CTL_CH3|ADC_CTL_IE);
	        ConfigAdc.ADC.AD3 = 1;
	    	 }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN4
	    case ADC4:{
	    	if(!ConfigAdc.ADC.AD4){
	        //
	        // Enable pin PD3 for ADC AIN4
	        //
	    		ROM_GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_3);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,0,4,ADC_CTL_CH4|ADC_CTL_IE);
	        ConfigAdc.ADC.AD4 = 1;
	    	}
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN5
	    case ADC5:{
	    	if(!ConfigAdc.ADC.AD5){

	        //
	        // Enable pin PD2 for ADC AIN5
	        //
	    		ROM_GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_2);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,0,5,ADC_CTL_CH5|ADC_CTL_IE);
	        ConfigAdc.ADC.AD5 = 1;
	    	}
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN6
	    case ADC6:{
	    	if(!ConfigAdc.ADC.AD6){

	        //
	        // Enable pin PD1 for ADC AIN6
	        //
	    		ROM_GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_1);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,0,6,ADC_CTL_CH6|ADC_CTL_IE);
	        ConfigAdc.ADC.AD6 = 1;
	    	}
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN7
	    case ADC7:{
	    	if(!ConfigAdc.ADC.AD7){

	        //
	        // Enable pin PD0 for ADC AIN7
	        //
	    		ROM_GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_0);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,0,7,ADC_CTL_CH7|ADC_CTL_END|ADC_CTL_IE);
	        ConfigAdc.ADC.AD7 = 1;
	    	}
	   	    	break;
	   	    }
#endif
#endif
#ifdef USEADC0SEQ1
#ifdef USEADC0SEQ1IN0
	    case ADC8:{
	    	if(!ConfigAdc.ADC.AD8){

	        //
	        // Enable pin PE5 for ADC AIN8
	        //
	    		ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_5);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,1,0,ADC_CTL_CH8|ADC_CTL_IE);
	        ConfigAdc.ADC.AD8 = 1;
	    	 }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ1IN1
	    case ADC9:{
	    	if(!ConfigAdc.ADC.AD9){
	    }
	        //
	       // Enable pin PE4 for ADC AIN9
	       //
	    	ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_4);
	    	ROM_ADCSequenceStepConfigure(ADC0_BASE,1,1,ADC_CTL_CH9|ADC_CTL_IE);
	       ConfigAdc.ADC.AD9 = 1;
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ1IN2
	    case ADC10:{
	    	if(!ConfigAdc.ADC.AD10){

	    	   //
	    	   // Enable pin PB4 for ADC AIN10
	    	   //
	    		ROM_GPIOPinTypeADC(GPIO_PORTB_BASE, GPIO_PIN_4);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,1,2,ADC_CTL_CH10|ADC_CTL_IE);
	    	   ConfigAdc.ADC.AD10 = 1;
	    	}
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ1IN3
	    case ADC11:{
	    	if(!ConfigAdc.ADC.AD11){

	        //
	        // Enable pin PB5 for ADC AIN11
	        //
	    		ROM_GPIOPinTypeADC(GPIO_PORTB_BASE, GPIO_PIN_5);
	    		ROM_ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_CH11|ADC_CTL_END|ADC_CTL_IE);
	        ConfigAdc.ADC.AD11 = 1;
	    	}
	   	    	break;
	   	    }
#endif
#endif
	    default:
	    	break;
}


#endif
}


int32_t TriggerADC(int8_t Sensor ){
#ifdef USEADC0
#ifdef USEADC0SEQ0
	ROM_ADCSequenceEnable(ADC0_BASE,0);
#endif
#ifdef USEADC0SEQ1
	ROM_ADCSequenceEnable(ADC0_BASE,1);
#endif
#ifdef USEADC0SEQ0
	ROM_ADCIntClear(ADC0_BASE, 0);
#endif
#ifdef USEADC0SEQ1
	ROM_ADCIntClear(ADC0_BASE, 1);
#endif
#ifdef USEADC0SEQ0
	 ADCProcessorTrigger(ADC0_BASE, 0);
#endif
#ifdef USEADC0SEQ1
	 ROM_ADCProcessorTrigger(ADC0_BASE, 1);
#endif

#ifdef USEADC0SEQ0
	uint32_t temp[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
#endif
#ifdef USEADC0SEQ1
	uint32_t temp2[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
#endif
	//Esperamos la conversion de las muestras
#ifdef USEADC0SEQ0
	while(! ROM_ADCIntStatus(ADC0_BASE, 0, false)){}
#endif
#ifdef USEADC0SEQ1
	while(! ROM_ADCIntStatus(ADC0_BASE, 1, false)){}
#endif
#ifdef USEADC0SEQ0
	ROM_ADCIntClear(ADC0_BASE, 0);
#endif
#ifdef USEADC0SEQ1
	ROM_ADCIntClear(ADC0_BASE, 1);
#endif
#ifdef USEADC0SEQ0
	ROM_ADCSequenceDataGet(ADC0_BASE, 0, temp);
#endif
#ifdef USEADC0SEQ1
	ROM_ADCSequenceDataGet(ADC0_BASE, 1, temp2);
#endif





switch(Sensor){
#ifdef USEADC0SEQ0
#ifdef USEADC0SEQ0IN0
	    case ADC0:{
	    	if(ConfigAdc.ADC.AD0){
	    		return temp[0];
	    	}
	    	break;
	    }
#endif
#ifdef USEADC0SEQ0IN1
	    case ADC1:{
	    	if(ConfigAdc.ADC.AD1){
	    		return temp[1];
	    	}
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN2
	    case ADC2:{
	    	if(ConfigAdc.ADC.AD2){
	    		return temp[2];
	    }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN3
	    case ADC3:{
	    	if(ConfigAdc.ADC.AD3){
	    		return temp[3];
	    }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN4
	    case ADC4:{
	    	if(ConfigAdc.ADC.AD4){
	    		return temp[4];
	    }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN5
	    case ADC5:{
	    	if(ConfigAdc.ADC.AD5){
	    		return temp[5];
	    }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN6
	    case ADC6:{
	    	if(ConfigAdc.ADC.AD6){
	    		return temp[6];
	    }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ0IN7
	    case ADC7:{
	    	if(ConfigAdc.ADC.AD7){
	    		return temp[7];
	    }
	   	    	break;
	   	    }
#endif
#endif
#ifdef USEADC0SEQ1
#ifdef USEADC0SEQ1IN0
	    case ADC8:{
	    	if(ConfigAdc.ADC.AD8){
	    		return temp2[0];
	    }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ1IN1
	    case ADC9:{
	    	if(ConfigAdc.ADC.AD9){
	    		return temp2[1];
	    }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ1IN2
	    case ADC10:{
	    	if(ConfigAdc.ADC.AD10){
	    		return temp2[2];
	    }
	   	    	break;
	   	    }
#endif
#ifdef USEADC0SEQ1IN3
	    case ADC11:{
	    	if(ConfigAdc.ADC.AD11){
	    		return temp2[3];
	    	}

	   	    	break;
	   	    }
#endif
#endif
	    default:
	    	break;
	}
#endif
return 0;

}

float LSBToVoltage(int32_t lsb){
	//Esto devuelve mV
	//Suponemos que la tension del dispositivo es 3v
	//Es decir que tenemos 3000 mV
	return (3000.0/4096.0)*(float)lsb;
}


