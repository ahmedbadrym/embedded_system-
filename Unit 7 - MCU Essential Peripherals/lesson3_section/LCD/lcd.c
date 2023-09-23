/*
 * lcd.c
 *
 *  Created on: Sep 21, 2023
 *      Author: THE GHOST
 */
#include"lcd.h"

GPIO_PIN_CONFIG P;
void delay_ms(int j)
{
	for(j=0;j<1000;j++);
}
void lcd_kick(void)
{
	//enable pin for synchronization
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, E, GPIO_PIN_ON);
	delay_ms(5);
	//disable pin for synchronization
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, E, GPIO_PIN_OFF);


}

void lcd_init()
{

	//RS,RW,E is output pins
	//RS
	delay_ms(5);
	RCC_GPIOA_CLK_EN();
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=RS;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(CONTROL_PINS, &P);
	//RW
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=RW;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(CONTROL_PINS, &P);
	//E
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=E;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(CONTROL_PINS, &P);
	/*DATA_PORT_dir=0xff; // data port is output*/
	//pA0
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=D0;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(Data_Port, &P);
	//pA1
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=D1;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(Data_Port, &P);
	//PA2
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=D2;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(Data_Port, &P);
	//PA3
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=D3;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(Data_Port, &P);
	//PA4
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=D4;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(Data_Port, &P);
	//PA5
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=D5;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(Data_Port, &P);
	//PA6
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=D6;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(Data_Port, &P);
	//PA7
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=D7;
	P.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(Data_Port, &P);
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, RS, GPIO_PIN_OFF);
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, RW, GPIO_PIN_OFF);
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, E, GPIO_PIN_OFF);
	delay_ms(30);
	//Function set
	send_cmd(0b00111000);//done
	delay_ms(1);
	//Display on/off
	send_cmd(0b00001111);//done
	delay_ms(1);
	//Display clear
	send_cmd(0b00000001);//done
	delay_ms(2);
	//Entry set
	send_cmd(0b00000011);//done

}
void send_cmd(u8 cmd)
{
	MCAL_GPIO_WRITE_PORT(Data_Port, cmd);
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, GPIO_PIN_8, GPIO_PIN_OFF);//RS=0 to enable command
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, RW, GPIO_PIN_OFF);//RW=0 to enable write
	lcd_kick();
}
void send_char(u8 data)
{
	MCAL_GPIO_WRITE_PORT(Data_Port, data);
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, RS, GPIO_PIN_ON);//to enable data RS=1
	MCAL_GPIO_WRITE_PIN(CONTROL_PINS, RW, GPIO_PIN_OFF);// to enable write RW=0
	lcd_kick();
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
			delay_ms(200);
		}
		else if(count>=16)
		{
			LCD_GoTO(2,(count-16));
			send_char(*str);
			str++;
			count++;
			delay_ms(200);
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


