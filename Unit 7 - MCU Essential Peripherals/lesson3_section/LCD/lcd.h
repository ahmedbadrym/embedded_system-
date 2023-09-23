/*
 * lcd.h
 *
 *  Created on: Sep 21, 2023
 *      Author: THE GHOST
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_
#include "int.h"
#include "stm32f103c6.h"
#define D0 GPIO_PIN_0
#define D1 GPIO_PIN_1
#define D2  GPIO_PIN_2
#define D3 GPIO_PIN_3
#define D4 GPIO_PIN_4
#define D5 GPIO_PIN_5
#define D6 GPIO_PIN_6
#define D7 GPIO_PIN_7
#define RS GPIO_PIN_8
#define RW GPIO_PIN_9
#define E  GPIO_PIN_10
#define CONTROL_PINS GPIOA
#define Data_Port GPIOA
typedef unsigned char u8;
typedef  signed int s32;





void lcd_init();
void send_cmd(u8 cmd);
void send_char(u8 data);
void send_str(u8 * str);
u8 LCD_SendNumber(s32 number);
void LCD_Clear(void);
void LCD_GoTO(u8 row, u8 clm);




#endif /* LCD_LCD_H_ */
