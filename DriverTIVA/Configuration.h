/*
 * Configuration.h
 *
 *  Created on: 29/03/2014
 *      Author: Admin
 *      Estructuras de administraccion de los perifericos
 *      Falta la compatibilidad entre multiplexacion de perifericos en pines
 *
 */

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__
#include <stdint.h>
#include "driverlib/rom.h"


//ADC's defines
#define ADC0   0x00 //PE3
#define ADC1   0x01 //PE2
#define ADC2   0x02	//PE1
#define ADC3   0x03 //PE0
#define ADC4   0x04 //PD3
#define ADC5   0x05 //PD2
#define ADC6   0x06 //PD1
#define ADC7   0x07 //PD0
#define ADC8   0x08 //PE5
#define ADC9   0x09 //PE4
#define ADC10  0x0A //PB4
#define ADC11  0x0B //PB5

//Defines de los tipos de sensores

#define GP2Y0A41SFK0F 0x00
#define GP2Y0A21YK 	  0x01
#define GP2D12        0x02


//PWM's defines



//Associations pin to signal
#define PWM0   0x00 //PB6
#define PWM1   0x01 //PB7
#define PWM2   0x02	//PB4
#define PWM3   0x03 //PB5
#define PWM4   0x04 //PE4
#define PWM5   0x05 //PE5
#define PWM6   0x06 //PC4
#define PWM7   0x07 //PC5
#define PWM8   0x08 //PD0
#define PWM9   0x09 //PD1
#define PWM10  0x0A //PA6
#define PWM11  0x0B //PA7
#define PWM12  0x0C //PF0
#define PWM13  0x0D //PF1
#define PWM14  0x0E //PF2
#define PWM15  0x0F //PF3


//Gpio defines

#define PA0 0x00
#define PA1 0x01
#define PA2 0x02
#define PA3 0x03
#define PA4 0x04
#define PA5 0x05
#define PA6 0x06
#define PA7 0x07
#define PB0 0x08
#define PB1 0x09
#define PB2 0x0A
#define PB3 0x0B
#define PB4 0x0C
#define PB5 0x0D
#define PB6 0x0E
#define PB7 0x0F
#define PC0 0x10
#define PC1 0x11
#define PC2 0x12
#define PC3 0x13
#define PC4 0x14
#define PC5 0x15
#define PC6 0x16
#define PC7 0x17
#define PD0 0x18
#define PD1 0x19
#define PD2 0x1A
#define PD3 0x1B
#define PD4 0x1C
#define PD5 0x1D
#define PD6 0x1E
#define PD7 0x1F
#define PE0 0x20
#define PE1 0x21
#define PE2 0x22
#define PE3 0x23
#define PE4 0x24
#define PE5 0x25
#define PE6 0x26
#define PE7 0x27
#define PF0 0x28
#define PF1 0x29
#define PF2 0x2A
#define PF3 0x2B
#define PF4 0x2C
#define PF5 0x2D
#define PF6 0x2E
#define PF7 0x2F




//Encoder's defines
#define QEI0 0x00
#define QEI1 0x01



//TIMER's defines

#define TM00  0x01  //PB6 for TIMER0 T0CCP0
#define TM01  0x02  //PB7 for TIMER0 T0CCP1
#define TM10  0x03  //PB4 for TIMER1 T1CCP0
#define TM11  0x04  //PB5 for TIMER1 T1CCP1
#define TM20  0x05  //PB0 for TIMER2 T2CCP0
#define TM21  0x06  //PB1 for TIMER2 T2CCP1
#define TM00b 0x07  //PF0 for TIMER0 T0CCP0
#define TM01b 0x08  //PF1 for TIMER0 T0CCP1
#define TM10b 0x09  //PF2 for TIMER1 T1CCP0
#define TM11b 0x0A  //PF3 for TIMER1 T1CCP1
#define TM20b 0x0B  //PF4 for TIMER2 T2CCP0
#define TM30  0x0C  //PB2 for TIMER3 T3CCP0
#define TM31  0x0D  //PB3 for TIMER3 T3CCP1
#define TM40  0x0E  //PC0 for TIMER4 T4CCP0
#define TM41  0x0F  //PC1 for TIMER4 T4CCP1
#define TM50  0x10  //PC2 for TIMER5 T5CCP0
#define TM51  0x20  //PC3 for TIMER5 T5CCP1
#define TMW00 0x30  //PC4 for WTIMER0 WT0CCP0
#define TMW01 0x40  //PC5 for WTIMER0 WT0CCP1
#define TMW10 0x50  //PC6 for WTIMER1 WT1CCP0
#define TMW11 0x60  //PC7 for WTIMER1 WT1CCP1
#define TMW20 0x70  //PD0 for WTIMER2 WT2CCP0
#define TMW21 0x80  //PD1 for WTIMER2 WT2CCP1
#define TMW30 0x90  //PD2 for WTIMER3 WT3CCP0
#define TMW31 0xA0  //PD3 for WTIMER3 WT3CCP1
#define TMW40 0xB0  //PD4 for WTIMER4 WT4CCP0
#define TMW41 0xC0  //PD5 for WTIMER4 WT4CCP1
#define TMW50 0xD0  //PD6 for WTIMER5 WT5CCP0
#define TMW51 0xE0  //PD7 for WTIMER5 WT5CCP1


//Defines de odometria:
#define radio 0.01 //Esta en metros, radio de la rueda
#define d 0.0001   //Esta en metros, distancia entre los ejes
#define M_PI 3.14159265358979323846
#define NumE 2.718281828

//Estruturas

typedef union  {
	struct{
		uint8_t PoA0:1;
		uint8_t PoA1:1;
		uint8_t PoA2:1;
		uint8_t PoA3:1;
		uint8_t PoA4:1;
		uint8_t PoA5:1;
		uint8_t PoA6:1;
		uint8_t PoA7:1;
		uint8_t PoB0:1;
		uint8_t PoB1:1;
		uint8_t PoB2:1;
		uint8_t PoB3:1;
		uint8_t PoB4:1;
		uint8_t PoB5:1;
		uint8_t PoB6:1;
		uint8_t PoB7:1;
		uint8_t PoC0:1;
		uint8_t PoC1:1;
		uint8_t PoC2:1;
		uint8_t PoC3:1;
		uint8_t PoC4:1;
		uint8_t PoC5:1;
		uint8_t PoC6:1;
		uint8_t PoC7:1;
		uint8_t PoD0:1;
		uint8_t PoD1:1;
		uint8_t PoD2:1;
		uint8_t PoD3:1;
		uint8_t PoD4:1;
		uint8_t PoD5:1;
		uint8_t PoD6:1;
		uint8_t PoD7:1;
		uint8_t PoE0:1;
		uint8_t PoE1:1;
		uint8_t PoE2:1;
		uint8_t PoE3:1;
		uint8_t PoE4:1;
		uint8_t PoE5:1;
		uint8_t PoE6:1;
		uint8_t PoE7:1;
		uint8_t PoF0:1;
		uint8_t PoF1:1;
		uint8_t PoF2:1;
		uint8_t PoF3:1;
		uint8_t PoF4:1;
		uint8_t PoF5:1;
		uint8_t PoF6:1;
		uint8_t PoF7:1;

	} GPIOS;
	uint8_t PortGpio[6];
}  GPIO;


typedef union  {
	struct{
		uint8_t AD0:1;
		uint8_t AD1:1;
		uint8_t AD2:1;
		uint8_t AD3:1;
		uint8_t AD4:1;
		uint8_t AD5:1;
		uint8_t AD6:1;
		uint8_t AD7:1;
		uint8_t AD8:1;
		uint8_t AD9:1;
		uint8_t AD10:1;
		uint8_t AD11:1;
	} ADC;
	uint8_t ADCS[2];
} AD;



typedef union  {
	struct{
		uint8_t PW0:1;
		uint8_t PW1:1;
		uint8_t PW2:1;
		uint8_t PW3:1;
		uint8_t PW4:1;
		uint8_t PW5:1;
		uint8_t PW6:1;
		uint8_t PW7:1;
		uint8_t PW8:1;
		uint8_t PW9:1;
		uint8_t PW10:1;
		uint8_t PW11:1;
		uint8_t PW12:1;
		uint8_t PW13:1;
		uint8_t PW14:1;
		uint8_t PW15:1;
	} PWM;
	uint8_t PWMS[2];
}  PW;


#ifdef USELCD
//Pin RESET PD0; CE PD1; DC PD2; CLK PD3; DIN PD6
#define PIN_RESET     GPIO_PIN_0
#define PIN_CE     	  GPIO_PIN_1
#define PIN_DC        GPIO_PIN_2
#define PIN_CLK		  GPIO_PIN_3
#define PIN_DIN		  GPIO_PIN_6



#define LCD_X     84
#define LCD_Y     48
#define LCD_COMANDO 0
#define LCD_DATO  1


//ASCII
static const uint8_t ASCII[][5] = {
  {0x00, 0x00, 0x00, 0x00, 0x00} // 20
  ,{0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
  ,{0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
  ,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
  ,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
  ,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
  ,{0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
  ,{0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
  ,{0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
  ,{0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
  ,{0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
  ,{0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
  ,{0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
  ,{0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
  ,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
  ,{0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
  ,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
  ,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
  ,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
  ,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
  ,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
  ,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
  ,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
  ,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
  ,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
  ,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
  ,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
  ,{0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
  ,{0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
  ,{0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
  ,{0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
  ,{0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
  ,{0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
  ,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
  ,{0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
  ,{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
  ,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
  ,{0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
  ,{0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
  ,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
  ,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
  ,{0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
  ,{0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
  ,{0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
  ,{0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
  ,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
  ,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
  ,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
  ,{0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
  ,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
  ,{0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
  ,{0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
  ,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
  ,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
  ,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
  ,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
  ,{0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
  ,{0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
  ,{0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
  ,{0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
  ,{0x02, 0x04, 0x08, 0x10, 0x20} // 5c \
  ,{}
  ,{0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
  ,{0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
  ,{0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
  ,{0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
  ,{0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
  ,{0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
  ,{0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
  ,{0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
  ,{0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
  ,{0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
  ,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
  ,{0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
  ,{0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
  ,{0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j
  ,{0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
  ,{0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
  ,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
  ,{0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
  ,{0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
  ,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
  ,{0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
  ,{0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
  ,{0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
  ,{0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
  ,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
  ,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
  ,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
  ,{0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
  ,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
  ,{0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
  ,{0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
  ,{0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
  ,{0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
  ,{0x10, 0x08, 0x08, 0x10, 0x08} // 7e ~
  ,{0x78, 0x46, 0x41, 0x46, 0x78} // 7f DEL
};


#endif

#endif
