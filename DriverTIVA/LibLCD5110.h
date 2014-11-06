/*
 * LibLCD.h
 *
 *  Created on: 20/10/2014
 *      Author: User
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
