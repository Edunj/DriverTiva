/*  LibLCD5110.c
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

#include "LibLCD5110.h"
#include <stdbool.h>
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Configuration.h"

//*****************************************************************************
//
//! Clear a LCD
//!
//! This function clear a LCD type 5110.
//!
//! \return none.
//
//*****************************************************************************
void LCDClear(void) {
#ifdef USELCD
	int index = 0;
  for (index=0 ; index < (LCD_X*LCD_Y) ; index++){
    LCDWrite(LCD_DATO, 0x00);
  }
  gotoXY(0, 0); //After we clear the display, return to the home position
#endif
}

//*****************************************************************************
//
//! Shift Out a byte
//!
//! \param val is a byte to shift out in the pin.
//!
//! This function shift out a byte in the pin PIN_DIR
//!
//! \return none.
//
//*****************************************************************************
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


//*****************************************************************************
//
//! Send a byte to LCD
//!
//! \param dato_o_comando is the type of data.
//! \param datos is a byte to send.
//!
//! This send a byte to the LCD.
//!
//! The \e  dato_o_comando can take on the following values:
//!
//! - \b  0    - data
//! - \b  1    - command
//!
//! \return none.
//
//*****************************************************************************
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


 //*****************************************************************************
 //
 //! This function positioning a cursor in (x,y)
 //!
 //! \param x is the x in pixels
 //! \param y is the y in pixels
 //!
 //! This function positioning a cursor in (x,y)
 //!
 //!
 //! \return none.
 //
 //*****************************************************************************
 void gotoXY(int x, int y) {
#ifdef USELCD
	 LCDWrite(LCD_COMANDO, 0x80 | x);  // Column.
	 LCDWrite(LCD_COMANDO, 0x40 | y);  // Row.  ?
#endif
 }


 //*****************************************************************************
 //
 //! Write a array the characters
 //!
 //! \param caracter is the pointer to first character in array.
 //!
 //! This function write a array the characters
 //!
 //! \return none.
 //
 //*****************************************************************************
 void LCDString(uint8_t *caracter) {
#ifdef USELCD
   while (*caracter)
     LCDCharacter(*caracter++);
#endif
 }



 //*****************************************************************************
 //
 //! Write a character
 //!
 //! \param caracter is the  character to print.
 //!
 //! This function write a character
 //!
 //! \return none.
 //
 //*****************************************************************************
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




 //*****************************************************************************
 //
 //! Init the display
 //!
 //! This function init the display in the pins specified in the configuration.h
 //!
 //! \return none.
 //
 //*****************************************************************************
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

