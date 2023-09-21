/*
 * int.h
 *
 *  Created on: Sep 19, 2023
 *      Author: THE GHOST
 */

#ifndef INC_INT_H_
#define INC_INT_H_
#include "stm32f103c6.h"
//-------------------------------
typedef struct
{
	uint16_t GPIO_PIN_NUMBER	;	  //specify gpio pins to be configured
									  //this parameter can be a value of @ref GPIO_PINS_DEFINE
	uint16_t GPIO_MODE;				  //specify gpio pins to be configured
		                          	  //this parameter can be a value of @ref GPIO_PINS_DEFINE
	uint16_t GPIO_OUT_SPEED;		  //specify output speed @ref GPIO output speed
}GPIO_PIN_CONFIG;
void MCAL_GPIO_Init(GPIO_Typedef* GPIOx, GPIO_PIN_CONFIG* PinConfig);

void MCAL_GPIO_DeInit(GPIO_Typedef* GPIOx);

void MCAL_GPIO_WRITE_PIN(GPIO_Typedef* GPIOx, uint16_t PinNum, uint8_t value);

void MCAL_GPIO_WRITE_PORT(GPIO_Typedef* GPIOx, uint16_t value);			 //returned values according to @ref pin R/W

uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef* GPIOx, uint16_t PinNum);      //returned values according to @ref pin R/W

uint16_t MCAL_GPIO_READ_PORT(GPIO_Typedef* GPIOx);

void MCAL_GPIO_TOGGLE_PIN(GPIO_Typedef* GPIOx, uint16_t PinNum);

uint8_t MCAL_GPIO_PIN_LOCK(GPIO_Typedef* GPIOx, uint16_t PinNum);    //returned values according to @ref GPIO lock pin






//@ref GPIO_PINS_DEFINE
#define GPIO_PIN_0   1<<0
#define GPIO_PIN_1   1<<1
#define GPIO_PIN_2   1<<2
#define GPIO_PIN_3   1<<3
#define GPIO_PIN_4   1<<4
#define GPIO_PIN_5   1<<5
#define GPIO_PIN_6   1<<6
#define GPIO_PIN_7   1<<7
#define GPIO_PIN_8   1<<8
#define GPIO_PIN_9   1<<9
#define GPIO_PIN_10  1<<10
#define GPIO_PIN_11  1<<11
#define GPIO_PIN_12  1<<12
#define GPIO_PIN_13  1<<13
#define GPIO_PIN_14  1<<14
#define GPIO_PIN_15  1<<15
//@ref GPIO Pin Mode
#define GPIO_INPUT_ANALOG				0
#define GPIO_INPUT_FLOATING				1
#define GPIO_INPUT_PU					2			//INPUT PULL UP
#define GPIO_INPUT_PD					3			//INPUT PULL DOWN
#define GPIO_OUTPUT_PUSHPULL			4			//output Push Pull
#define GPIO_OUTPUT_OPENDRAIN			5
#define GPIO_OUTPUT_AF_PUSHPULL			6			//AFIO OUTPUT
#define GPIO_OUTPUT_AF_OPENDRAIN		7			//AFIO OUTPUT
#define GPIO_AF_INPUT					8			//AFIO INPUT



//@ref GPIO output speed
#define GPIO_OUTPUT_10M  1 					// Output mode, max speed 10 MHz.
#define GPIO_OUTPUT_2M  2 					// Output mode, max speed 2 MHz.
#define GPIO_OUTPUT_50M  3		  			// Output mode, max speed 50 MHz.


//@ref GPIO lock pin
#define GPIO_pin_locked_done    1 					// if the pin is locked.
#define GPIO_pin_locked_failed  0 					// if the pin is not locked.



//@ref pin R/W
#define GPIO_PIN_ON		1     //set or on
#define GPIO_PIN_OFF	0     //reset or off





#endif /* INC_INT_H_ */
