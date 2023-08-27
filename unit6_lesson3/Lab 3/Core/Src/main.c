
typedef volatile unsigned int vint32_t ;
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define RCC_BASE     0x40021000
#define GPIOA_BASE   0x40010800

#define RCC_APB2ENR  *(vint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH    *(vint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_ODR    *(vint32_t *) (GPIOA_BASE + 0x0c)
#define RCC_CFGR     *(vint32_t *) (RCC_BASE + 0x04)
#define RCC_CR       *(vint32_t *) (RCC_BASE + 0x00)

int main(void)
{

  RCC_CFGR |= (0b10 << 0);
  RCC_CFGR |= (0b0110 << 18);
  RCC_CR   |= (1 << 24) ;
  RCC_CFGR |= (0b101 << 11);
  RCC_CFGR |= (0b100 << 8);

	GPIOA_CRH &=0xff0fffff;
	GPIOA_CRH |=0x00200000;

	while (1)
	{
		GPIOA_ODR |=1<<13;
		for (int i=0;i<5000;i++);
		GPIOA_ODR &=~(1<<13);
		for (int i=0;i<5000;i++);
	}

	return 0;
}
