
#include "int.h"
#include "stm32f103c6.h"
#include <stdlib.h>
void clock_init(void)
{
	//Enable Clock gpiA
	RCC_GPIOA_CLK_EN();
	//Enable Clock gpiB
	RCC_GPIOB_CLK_EN();
}

void delay(int x)
{
	int i, j;

	for(i=0; i<x; i++)
	{
		for(j=0;j<255;j++);
	}
}
void GPIO_init(void)
{

	GPIO_PIN_CONFIG P;
	//PA1 input high z
	P.GPIO_MODE=GPIO_INPUT_FLOATING;
	P.GPIO_PIN_NUMBER=GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA, &P);

	//PA13 input high z
	P.GPIO_MODE=GPIO_INPUT_FLOATING;
	P.GPIO_PIN_NUMBER=GPIO_PIN_13;
	MCAL_GPIO_Init(GPIOA, &P);

	//pB1 out PP 10MHZ
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=GPIO_PIN_1;
	P.GPIO_OUT_SPEED =GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(GPIOB, &P);

	//PB13 OUT PUSH PULL
	P.GPIO_MODE=GPIO_OUTPUT_PUSHPULL;
	P.GPIO_PIN_NUMBER=GPIO_PIN_13;
	P.GPIO_OUT_SPEED =GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(GPIOB, &P);
}
int main(void)
{
	clock_init();
	GPIO_init();


	while(1)
	{
		//PA1 connected with pull up external
		if(!MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_1))
		{
			MCAL_GPIO_TOGGLE_PIN(GPIOB, GPIO_PIN_1);
			//condition for single pressing
			while(!MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_1));
		}
		//PA13 connected with pull down external
		if(MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_13))
		{
			MCAL_GPIO_TOGGLE_PIN(GPIOB, GPIO_PIN_13);
		}

		delay(2);

	}

	return 0;
}
