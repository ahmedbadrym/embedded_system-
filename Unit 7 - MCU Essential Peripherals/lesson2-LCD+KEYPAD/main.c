/*
 * GccApplication1.c
 *
 * Created: 9/18/2023 5:23:34 PM
 * Author : THE GHOST
 */ 
#define F_CPU 8000000
#include "LCD/int.h"
#include  "KEYPAD/int.h"

#include <avr/io.h>




unsigned char pressed_key;


void main(){
	lcd_init();
	KEYPAD_init();
	while(1){
		pressed_key=Get_Pressed_KEY();
		switch(pressed_key){
			case 'N':
			break;
			case 'D':
			LCD_Clear();
			break;
			default:
			send_char(pressed_key);
		}

	}




}
