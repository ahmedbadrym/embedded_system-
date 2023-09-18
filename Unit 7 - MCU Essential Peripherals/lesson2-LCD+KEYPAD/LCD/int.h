/*
 * int.h
 *
 * Created: 9/18/2023 5:32:26 PM
 *  Author: THE GHOST
 */ 

#ifndef HAL_LCD_INT_H_
#define HAL_LCD_INT_H_
typedef unsigned char u8;
typedef  signed int s32;





void lcd_init();
void send_cmd(u8 cmd);
void send_char(u8 data);
void send_str(u8 * str);
u8 LCD_SendNumber(s32 number);
void LCD_Clear(void);
void LCD_GoTO(u8 row, u8 clm);




#endif /* HAL_LCD_INT_H_ */
