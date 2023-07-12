#define SYSCTRL_Base              0x400FE000
#define GPIO_PORTF_Base           0x40025000

#define SYSCTRL_RCGC2_R   (*(volatile unsigned long *)(SYSCTRL_Base+0X108))
#define GPIO_PORTF_DIR_R  (*(volatile unsigned long *)(GPIO_PORTF_Base+0x400))
#define GPIO_PORTF_DEN_R  (*(volatile unsigned long *)(GPIO_PORTF_Base+0X51C))
#define GPIO_PORTF_DATA_R (*(volatile unsigned long *)(GPIO_PORTF_Base+0x3FC))

int main()
{
   SYSCTRL_RCGC2_R |= 0x20;
    volatile int i;
    for (i = 0; i < 250; i++)
        ;

    GPIO_PORTF_DIR_R |= 1 << 3;
    GPIO_PORTF_DEN_R |= 1 << 3;

    while (1)
    {
        GPIO_PORTF_DATA_R |= (1 << 3);
        for (i = 0; i < 500000; i++);
            
        GPIO_PORTF_DATA_R &= ~(1 << 3);
        for (i = 0; i < 500000; i++);
            
    }

    return 0;
}
