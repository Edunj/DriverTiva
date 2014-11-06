/*
 * LibLCD.c
 *
 *  Created on: 20/10/2014
 *      Author: User
 */

#include "LibLCD5110.h"
#include <stdbool.h>
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Configuration.h"


void LCDClear(void) {
#ifdef USELCD
	int index = 0;
  for (index=0 ; index < (LCD_X*LCD_Y) ; index++){
    LCDWrite(LCD_DATO, 0x00);
  }
  gotoXY(0, 0); //After we clear the display, return to the home position
#endif
}


void shiftOut( uint8_t val)
{
#ifdef USELCD
	uint8_t i;


	for (i = 0; i < 8; i++)  {


			if(( val << i)&0x80){
				ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_DIN,PIN_DIN);
			}else{
				ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_DIN,~PIN_DIN);
			}

			ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_CLK,PIN_CLK);

			ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_CLK,~PIN_CLK);
}
#endif
}



 void LCDWrite(uint8_t dato_o_comando, uint8_t datos){
#ifdef USELCD
	 if(dato_o_comando){
		 ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_DC, PIN_DC);
	 }else{
		 ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_DC, ~PIN_DC);
	 }
	 ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_CE,~PIN_CE);

	shiftOut(datos);

	ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_CE,PIN_CE);
#endif
}

 void gotoXY(int x, int y) {
#ifdef USELCD
	 LCDWrite(LCD_COMANDO, 0x80 | x);  // Column.
	 LCDWrite(LCD_COMANDO, 0x40 | y);  // Row.  ?
#endif
 }

 void LCDString(uint8_t *caracter) {
#ifdef USELCD
   while (*caracter)
     LCDCharacter(*caracter++);
#endif
 }


 void LCDCharacter(uint8_t caracter) {
#ifdef USELCD
   LCDWrite(LCD_DATO, 0x00); //Blank vertical line padding
  volatile int index = 0;
   for (index; index < 5 ; index++){
     LCDWrite(LCD_DATO, ASCII[caracter - 0x20][index]);
     //0x20 is the ASCII character for Space (' '). The font table starts with this character


   }
   LCDWrite(LCD_DATO, 0x00); //Blank vertical line padding
#endif
 }





 void LCDInit(void){
#ifdef USELCD

	 ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	 ROM_GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, PIN_RESET|PIN_CE|PIN_DC|PIN_DIN|PIN_CLK);



	  //Protocol to Init
	 ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_RESET,~PIN_RESET);


	 ROM_GPIOPinWrite(GPIO_PORTD_BASE,PIN_RESET,PIN_RESET);


	    LCDWrite(LCD_COMANDO, 0x21);
	    LCDWrite(LCD_COMANDO, 0xB3);
	    LCDWrite(LCD_COMANDO, 0x04);
	    LCDWrite(LCD_COMANDO, 0x14);
	    LCDWrite(LCD_COMANDO, 0x20);
	    LCDWrite(LCD_COMANDO, 0x0C);
#endif
}

