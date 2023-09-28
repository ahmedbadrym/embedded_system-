
#include "stm32f103c6.h"
#include "stm32f103c6gpio.h"
#include "stm32f103c6exti.h"
#include "lcd.h"
uint16_t flag=0;
void wait_ms(int x)
{
	for(int j=0;j<x;j++)
	{
	for(int i=0;i<256;i++);
	}

}
void EXTI_CALLBACK (void)
{
	flag=1;
	send_str("IRQ 9 IS HAPPENNED");
	  wait_ms(10);


}
void main(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	lcd_init();
	EXTI_Pinconfig CFG;
	//give  a struct as macro
	CFG.exti_pin=EXTI9PB9;
	CFG.trigger=EXTI_RISING;
	CFG.call_back_func=EXTI_CALLBACK;
	CFG.IRQ_EN=IRQ_ENABLE;
	MCAL_GPIO_EXTI_Update(&CFG);
    flag=1;

	while(1)
	{
		if(flag)
		{
			LCD_Clear();
		}
		  wait_ms(5);

	}
}
