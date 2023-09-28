/*

 * stm32f103c6.c
 *
 *  Created on: Sep 19, 2023
 *      Author: THE GHOST
 */
#include "stm32f103c6gpio.h"
#include "stm32f103c6exti.h"
//array of pointer to functions
void(*Gp_call_back_func[15]) (void);

//==============================MACROS=============================

#define AFIO_MAPPING(x)          ( (x==GPIOA)?0:\
		                           (x==GPIOB)?1:\
				                   (x==GPIOC)?2:\
						           (x==GPIOD)?3:0 )

/*
 * =======================================================================================
 * 										GENERIC FUNCTIONS
 * =======================================================================================
 */

void NVIC_ENABLE(uint16_t IRQ){
	switch(IRQ){
	case EXTI0:
		NVIC_IRQ6_EXTI0_EN();
		break;
	case EXTI1:
		NVIC_IRQ7_EXTI1_EN();
		break;
	case EXTI2:
		NVIC_IRQ8_EXTI2_EN();
		break;
	case EXTI3:
		NVIC_IRQ9_EXTI3_EN();
		break;
	case EXTI4:
		NVIC_IRQ10_EXTI4_EN();
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_EN();
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_EN();
		break;
	}

}


void NVIC_DISABLE(uint16_t IRQ)
{
	switch(IRQ)
	{
	case EXTI0:
		NVIC_IRQ6_EXTI0_Dis();
		break;

	case EXTI1:
		NVIC_IRQ7_EXTI1_Dis();
		break;

	case EXTI2:
		NVIC_IRQ8_EXTI2_Dis();
		break;

	case EXTI3:
		NVIC_IRQ9_EXTI3_Dis();
		break;

	case EXTI4:
		NVIC_IRQ10_EXTI4_Dis();
		break;

	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_Dis();
		break;

	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_Dis();
		break;
	}
}


/*====================================================================
 * @fn                 MCAL_GPIO_EXTI_Deinit
 * @breif              disable mask"PIE"  and NVIC "GIE"
			               cause there is no register in RCC  for disable EXTI
 *@param                void
 *@retval 			   void
 *@note                 we disable it bu retuen EXTI reg to default values
 *====================================================================
 */

void MCAL_GPIO_EXTI_Deinit (void)
{
	EXTI->IMR=0x00000000;
	EXTI->EMR=0x00000000;
	EXTI->FTSR=0x00000000;
	EXTI->RTSR=0x00000000;
	EXTI->SWIER=0x00000000;
	EXTI->PR=0xFFFFFFFF;

	NVIC_IRQ6_EXTI0_Dis();
	NVIC_IRQ7_EXTI1_Dis();
	NVIC_IRQ8_EXTI2_Dis();
	NVIC_IRQ9_EXTI3_Dis();
	NVIC_IRQ10_EXTI4_Dis();
	NVIC_IRQ23_EXTI5_9_Dis();
	NVIC_IRQ40_EXTI10_15_Dis();


}

/*====================================================================
 * @fn                 MCAL_GPIO_EXTI_Update
 * @breif             init exti pin routing

 *@param                struct EXTI_Pinconfig
 *@retval 			   void
 *@note                it can work as init and update at runtime
 *====================================================================
 */
void MCAL_GPIO_EXTI_Update ( EXTI_Pinconfig* exti_config)
{
	//1-configure GPIO to be i/p floating
	GPIO_PIN_CONFIG PINCONF;
	PINCONF.GPIO_MODE=GPIO_INPUT_FLOATING;
	PINCONF.GPIO_PIN_NUMBER=exti_config->exti_pin.gpio_pin;
	MCAL_GPIO_Init( (exti_config->exti_pin.gpio_port ),&PINCONF);
	//=============================================
	//2-Update AFIO to route EXTI line to which PORT "EXTI0 route to PA0or PB0 or PC0"
	// we have  4 registers for mapping  EXTICR1"EXTI0 TO EXTI3"
	//EXTICR2"EXTI4 TO EXTI7"--- EXTICR3"EXTI8 TO EXTI11"- EXTICR4"EXTI12 TO EXTI15"
	uint8_t index = (exti_config->exti_pin.exti_line)/4;
	uint8_t position = ((exti_config->exti_pin.exti_line) % 4)*4;
	AFIO->EXTICR[index] &= ~(0xF<<position);
	AFIO->EXTICR[index] |=  ((AFIO_MAPPING(exti_config->exti_pin.gpio_port) & 0xF) <<position ) ;
	//==============================================
	//3- enable trigger case
	//clear bit of rising
	EXTI->RTSR &= ~(1<<exti_config->exti_pin.exti_line);
	//clear bit of falling
	EXTI->FTSR &= ~(1<<exti_config->exti_pin.exti_line);

	if(exti_config->trigger==EXTI_RISING)
	{
		EXTI->RTSR |=(1<<exti_config->exti_pin.exti_line);
	}
	else if(exti_config->trigger==EXTI_FALLING)
	{
		EXTI->FTSR |=(1<<exti_config->exti_pin.exti_line);
	}
	else if(exti_config->trigger==EXTI_RISING_FALLING)
	{
		EXTI->RTSR |=(1<<exti_config->exti_pin.exti_line);
		EXTI->FTSR |=(1<<exti_config->exti_pin.exti_line);
	}
	//arr[0]=pointer to a func
	Gp_call_back_func[exti_config->exti_pin.exti_line]=exti_config->call_back_func;

	//enable MASK & NVIC
	if(exti_config->IRQ_EN==IRQ_ENABLE)
	{
		 //enable mask
	EXTI->IMR |= (1<<exti_config->exti_pin.exti_line);
	    //enable NVIC
	 NVIC_ENABLE(exti_config->exti_pin.exti_line);
	}
	else if(exti_config->IRQ_EN==IRQ_DISABLE)
	{
		 //diable mask
	EXTI->IMR &= ~(1<<exti_config->exti_pin.exti_line);
	    //disable NVIC
	 NVIC_DISABLE(exti_config->exti_pin.exti_line);
	}

}
void MCAL_GPIO_EXTI_Init ( EXTI_Pinconfig* exti_config)
{

	MCAL_GPIO_EXTI_Update(exti_config);

}

//=========================================ISR==============================================
void EXTI0_IRQHandler(void)
{
	//write 1 to clear pending bit,to stop sending interrupt again
	EXTI->PR = 1<<0;
	//callback
	Gp_call_back_func[0]();
}


void EXTI1_IRQHandler(void)
{
	EXTI->PR = 1<<1;
	Gp_call_back_func[1]();
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR = 1<<2;
	Gp_call_back_func[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR = 1<<3;
	Gp_call_back_func[3]();
}



void EXTI4_IRQHandler(void)
{
	EXTI->PR = 1<<4;
	Gp_call_back_func[4]();
}



void EXTI9_5_IRQHandler(void)
{
    /* here i check which interrupt is that, cause all interrupts from
	 5---9  arrived on same pin at NVIC
	so we will know which interrupt for ,by checking PR register if its one so its
	and then we write 1 on PR reg to disable interrupt  */
	if(EXTI->PR & 1<<5) { EXTI->PR  = 1<<5;   Gp_call_back_func[5](); }
	if(EXTI->PR & 1<<6) { EXTI->PR  = 1<<6;   Gp_call_back_func[6](); }
	if(EXTI->PR & 1<<7) { EXTI->PR  = 1<<7;   Gp_call_back_func[7](); }
	if(EXTI->PR & 1<<8) { EXTI->PR  = 1<<8;   Gp_call_back_func[8](); }
	if(EXTI->PR & 1<<9) { EXTI->PR  = 1<<9;   Gp_call_back_func[9](); }
}



void EXTI15_10_IRQHandler(void){

	if( EXTI->PR & 1<<10 ) { EXTI->PR |= 1<<10; Gp_call_back_func[10](); }
	if( EXTI->PR & 1<<11 ) { EXTI->PR |= 1<<11; Gp_call_back_func[11](); }
	if( EXTI->PR & 1<<12 ) { EXTI->PR |= 1<<12; Gp_call_back_func[12](); }
	if( EXTI->PR & 1<<13 ) { EXTI->PR |= 1<<13; Gp_call_back_func[13](); }
	if( EXTI->PR & 1<<14 ) { EXTI->PR |= 1<<14; Gp_call_back_func[14](); }
	if( EXTI->PR & 1<<14 ) { EXTI->PR |= 1<<15; Gp_call_back_func[15](); }
}
