/*
 * CFile1.c
 *
 * Created: 9/18/2023 5:32:42 PM
 *  Author: THE GHOST
 */ 
/*
 * prg.c
 *
 *  Created on: Aug 24, 2023
 *      Author: THE GHOST
 */
#include "int.h"
#include <util/delay.h>
#include <avr/io.h>
#define DATA_PORT_val PORTC 
#define DATA_PORT_dir DDRC
#define CONTROL_PINS_val PORTD
#define CONTROL_PINS_dir DDRD


void lcd_init()
{

	CONTROL_PINS_dir=0x07;//RS,RW,E is output pins
 DATA_PORT_dir=0xff; // data port is output
	_delay_ms(30);
	//Function set
	send_cmd(0b00111000);
	_delay_ms(1);
	//Display on/off
	send_cmd(0b00001111);
	_delay_ms(1);
	//Display clear
	send_cmd(0b00000001);

	_delay_ms(2);
	//Entry set
	send_cmd(0b00000011);

}
void send_cmd(u8 cmd)
{
	//to enable cmd not data RS=0
	// to enable write RW=0
	CONTROL_PINS_val=0x00;
	DATA_PORT_val=cmd;
	//enable pin for synchronization
	CONTROL_PINS_val=0x04;
	_delay_ms(2);
	//disable enable pin
	CONTROL_PINS_val=0x00;
}
void send_char(u8 data)
{
	//to enable data RS=1
	// to enable write RW=0
	CONTROL_PINS_val=0x01;
	// write data
	DATA_PORT_val=data;
	//enable pin for synchronization
	CONTROL_PINS_val=0x05;
	_delay_ms(10);
	CONTROL_PINS_val=0x01;

}
void send_str(u8 * str)
{
	u8 count=0;
	while(*str!='\0')
	if(count<16)

	{
		send_char(*str);
		str++;
		count++;
		_delay_ms(200);
	}
	else if(count>=16)
	{
	LCD_GoTO(2,(count-16));
	send_char(*str);
	str++;
	count++;
	_delay_ms(200);
	}
	
}
void LCD_GoTO(u8 row, u8 clm)
{
	switch(row)
	{
	case 1: send_cmd(128+clm);	break;
	case 2: send_cmd(192+clm);	break;
	}
}

void LCD_Clear(void)
{
	//clear
	send_cmd(0b00000001);
}



u8 LCD_SendNumber(s32 number)
{
	int copy = 0;
	if(number==0)
	{
		send_char('0');
		return 0;
	}
	if(number<0)
	{
		send_char('-');
		number *= -1;
	}
	if(number%10==0)
	{
		while(number)
		{

			copy *=10 ;//0
			copy += number %10 ;//5
			number /= 10;//5
		}
		while(copy)
			{
				send_char('0'+(copy %10));
				send_char('0');
				copy /=10 ;
			}
	}
	else{
	while(number)
	{
		copy *=10 ;//0
		copy += number %10 ;//5
		number /= 10;//5
	}
	while(copy)
	{
		send_char('0'+(copy %10));
		copy /=10 ;
	}
	}

}

