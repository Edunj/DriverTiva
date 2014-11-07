/*  LibLCD5110.h
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

#ifndef  __DRIVERTIVA_LIBLCD_H_
#define __DRIVERTIVA_LIBLCD_H_

#include <stdint.h>



//Prototipos para uso de LCD tipo nokia 84x48 caracteres
extern void gotoXY(int x, int y) ;
extern void LCDCharacter(uint8_t caracter);
extern void LCDString(uint8_t *caracter);
extern void LCDClear(void);
extern void LCDInit(void);
extern void LCDWrite(uint8_t dato_o_comando, uint8_t datos);
extern void shiftOut( uint8_t val);



#endif /* LIBLCD_H_ */
