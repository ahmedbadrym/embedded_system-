typedef volatile unsigned int vint32_t ;
#include <stdio.h>
#include <stdlib.h>
#define RCC_BASE     0x40021000
#define RCC_APB2ENR  *(vint32_t *) (RCC_BASE + 0x18)
#define RCC_CFGR     *(vint32_t *) (RCC_BASE + 0x04)
#define RCC_IOPAEN  (1<<2)

#define GPIOA_BASE   0x40010800
#define GPIOA_CRL    *(vint32_t *) (GPIOA_BASE + 0x00)
#define GPIOA_CRH    *(vint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_IDR    *(vint32_t *) (GPIOA_BASE + 0x08)
#define GPIOA_ODR    *(vint32_t *) (GPIOA_BASE + 0x0C)


#define GPIOB_BASE   0x40010C00
#define GPIOB_CRL    *(vint32_t *) (GPIOB_BASE + 0x00)
#define GPIOB_CRH    *(vint32_t *) (GPIOB_BASE + 0x04)
#define GPIOB_IDR    *(vint32_t *) (GPIOB_BASE + 0x08)
#define GPIOB_ODR    *(vint32_t *) (GPIOB_BASE + 0x0C)
void clock_init(void)
{
	//Enable Clock gpiA
	RCC_APB2ENR |= 1<<2;
	//Enable Clock gpiB
	RCC_APB2ENR |= 1<<3;
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

	//PA1 input high z
	GPIOA_CRL |= 1<<6;
	GPIOA_CRL &= ~(1<<7);
	//PA13 input high z
	GPIOA_CRH |= (1<<22);
	GPIOA_CRH &= ~(1<<23);

	//CNF PB1
	GPIOB_CRL &= ~(0b11<<6);
	//MODE
	GPIOB_CRL |= 1<<4;

	//PB13 OUT PUSH PULL
	GPIOB_CRH |= (0b01 << 20);
	GPIOB_CRH &= ~(0b11 << 22);
}
int main(void)
{
	clock_init();
	GPIO_init();


	while(1)
		{
		if(((GPIOA_IDR & (1<<1)) >> 1) == 0)
		{
			GPIOB_ODR ^= 1<<1;

			while(((GPIOA_IDR & (1<<1)) >> 1) == 0);
		}

		if(((GPIOA_IDR & (1<<13)) >> 13) == 1)
		{
			GPIOB_ODR ^= 1<<13;
		}

		delay(2);

		}

	return 0;
}
