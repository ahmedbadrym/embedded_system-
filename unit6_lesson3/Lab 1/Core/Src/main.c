typedef volatile unsigned int vint32_t ;
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define GPIO_BASE 0x40010800
#define GPIO_CRH  *(vint32_t*)(GPIO_BASE+0x04)
#define GPIO_ODR  *(vint32_t*)(GPIO_BASE+0x0C)
int main()
{
	GPIO_CRH &=0xff0fffff;
	GPIO_CRH &=0x00200000;
	while(1)
	{
		GPIO_ODR|=1<<13;
		for(int i=0;i<5000;++i);
		GPIO_ODR&=~(1<<13);
		for(int i=0;i<5000;++i);
	}

	return 0;
}
