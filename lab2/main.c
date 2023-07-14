#define Rcc_base 0x40021000
#define Gpio_base 0x40010800
#define Rcc_Ap *((volatile unsigned int *) (Rcc_base + 0x18))
#define gpio_c *((volatile unsigned int *) (Gpio_base + 0x04))
#define gpio_odr *((volatile unsigned int *) (Gpio_base + 0x0c))

typedef volatile unsigned int vint_32;

typedef union {
    vint_32 allfields;
    struct {
        vint_32 reserved : 13;
        vint_32 pin13 : 1;
    } pin;
} R_ODR_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *) (Gpio_base + 0x0c);

int main(void)
{
    Rcc_Ap |= 1 << 2;
    gpio_c &= 0xff0fffff;
    gpio_c |= 0x00200000;
    
    while (1) {
int i;
        R_ODR->pin.pin13 = 1;
        for ( i = 0; i < 5000; i++);
        
        R_ODR->pin.pin13 = 0;
        for ( i = 0; i < 5000; i++);
    }
    
    return 0;
}
