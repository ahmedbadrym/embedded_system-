/*
 * stm32f103c6.c
 *
 *  Created on: Sep 19, 2023
 *      Author: THE GHOST
 */
#include "inc/int.h"
uint32_t position (uint16_t pin)
{
	switch(pin)
	{
	case GPIO_PIN_0: return 0;
	case GPIO_PIN_1: return 4;
	case GPIO_PIN_2: return 8;
	case GPIO_PIN_3: return 12;
	case GPIO_PIN_4: return 16;
	case GPIO_PIN_5: return 20;
	case GPIO_PIN_6: return 24;
	case GPIO_PIN_7: return 28;
	case GPIO_PIN_8: return 0;
	case GPIO_PIN_9: return 4;
	case GPIO_PIN_10: return 8;
	case GPIO_PIN_11: return 12;
	case GPIO_PIN_12: return 16;
	case GPIO_PIN_13: return 20;
	case GPIO_PIN_14: return 24;
	case GPIO_PIN_15: return 28;
	}


}
void MCAL_GPIO_Init(GPIO_Typedef* GPIOx, GPIO_PIN_CONFIG* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) configure pins from pin0 to pin7
	//Port configuration register high (GPIOx_CRH) configure pins from pin8 to pin15
	volatile uint32_t* configreg=NULL;
	configreg =((PinConfig->GPIO_PIN_NUMBER) < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;
	//to clear CNF and MODE of the chosen bit
	*configreg &= ~(0xf<< position(PinConfig->GPIO_PIN_NUMBER));
	uint8_t pinconfig=0;
	//we will check if its output or not
	if(PinConfig->GPIO_MODE==GPIO_OUTPUT_PUSHPULL || PinConfig->GPIO_MODE==GPIO_OUTPUT_AF_OPENDRAIN || PinConfig->GPIO_MODE==GPIO_OUTPUT_OPENDRAIN || PinConfig->GPIO_MODE==GPIO_OUTPUT_AF_PUSHPULL)
	{
		/*// here i know its output but dont know mode of output or speed
	//here i want to know which output mode pin work
	// i shift PinConfig->GPIO_MODE-4 by 2 to put it in CNF bits
	// PinConfig->GPIO_OUT_SPEED & 0x0f cause speed is only decimal number*/
		pinconfig= (((PinConfig->GPIO_MODE-4)<<2) | (PinConfig->GPIO_OUT_SPEED & 0x0f));
		//to set CNF and MODE of the chosen bit
	}
	//check its input
	else
	{
		//check its i/p analog and i/p floating
		if (PinConfig->GPIO_MODE==GPIO_INPUT_ANALOG || PinConfig->GPIO_MODE==GPIO_INPUT_FLOATING)
		{
			//mode 00 ther only CNF that want cofigured
			pinconfig= (PinConfig->GPIO_MODE<<2) ;
			//to set CNF and MODE of the chosen bit
		}
		//check its AF i/p
		else if(PinConfig->GPIO_MODE==GPIO_AF_INPUT)
		{

			pinconfig= ( GPIO_INPUT_FLOATING<<2) ;//AF same as i/p floating
		}
		//check its i/p PU and i/p PD
		else
		{
			//mode and  CNF always is ob10  if its i/p PD or  i/p PU
			//odr thats resbosible for make it PD or PU
			pinconfig= 2<<2;

			if(PinConfig->GPIO_MODE==GPIO_INPUT_PU)
				GPIOx->ODR |= PinConfig->GPIO_PIN_NUMBER;
			else
				GPIOx->ODR &= ~(PinConfig->GPIO_PIN_NUMBER);
		}
	}

	//to set CNF and MODE of the chosen bit
	*configreg |= (pinconfig <<position(PinConfig->GPIO_PIN_NUMBER));
}

void MCAL_GPIO_DeInit(GPIO_Typedef* GPIOx)
{
	if(GPIOx==GPIOA)
	{
		RCC->APB2RSTR |=1<<2;
		RCC->APB2RSTR &=(1<<2);
	}
	else if(GPIOx==GPIOB)
	{
		RCC->APB2RSTR |=1<<3;
		RCC->APB2RSTR &=(1<<3);
	}
	else if(GPIOx==GPIOC)
	{
		RCC->APB2RSTR |=1<<4;
		RCC->APB2RSTR &=(1<<4);
	}
	else if(GPIOx==GPIOD)
	{
		RCC->APB2RSTR |=1<<5;
		RCC->APB2RSTR &=(1<<5);
	}
	else if(GPIOx==GPIOE)
	{
		RCC->APB2RSTR |=1<<6;
		RCC->APB2RSTR &=(1<<6);
	}
}

void MCAL_GPIO_WRITE_PIN(GPIO_Typedef* GPIOx, uint16_t PinNum, uint8_t value)
{
	if(value==0)
		GPIOx->ODR |= PinNum;
	else
		GPIOx->ODR &= ~(PinNum);
}

void MCAL_GPIO_WRITE_PORT(GPIO_Typedef* GPIOx, uint16_t value)
{
	GPIOx->ODR=value;

}

uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef* GPIOx, uint16_t PinNum)
{
	if(GPIOx->IDR & PinNum)
		return 1;
	else
		return 0;
}

uint16_t MCAL_GPIO_READ_PORT(GPIO_Typedef* GPIOx)
{
	uint16_t x=(uint16_t) GPIOx->IDR;
	return x;

}
void MCAL_GPIO_TOGGLE_PIN(GPIO_Typedef* GPIOx, uint16_t PinNum)
{
	GPIOx->ODR ^= PinNum;
	/*if(GPIOx->ODR & PinNum)	// check if pin is 0
		GPIOx->ODR & ~(PinNum);
	else
		GPIOx->ODR | (PinNum);*/

}

uint8_t MCAL_GPIO_PIN_LOCK(GPIO_Typedef* GPIOx, uint16_t PinNum)
{
volatile uint32_t temp = 1<<16 | PinNum;
//set bit 16 to lock and bit number want to be locked
GPIOx->LCKR= temp;
//write 0 on bit 16 of locker
GPIOx->LCKR= PinNum;
//write 1 on bit 16 of locker
GPIOx->LCKR= temp;
//read
temp=GPIOx->LCKR;
if((uint32_t) temp & 1<<16)
{
	return GPIO_pin_locked_done;
}
return GPIO_pin_locked_failed;

}




