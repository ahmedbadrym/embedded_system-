#include <stdint.h>
 

extern int main(void);

void reset_handler(void);

void default_handler(void)
{
    reset_handler();
}

void NMI_handler(void) __attribute__((weak, alias("default_handler")));;
void h_fault_handler(void) __attribute__((weak, alias("default_handler")));;
void mm_fault_handler(void) __attribute__((weak, alias("default_handler")));;
void bus_fault(void) __attribute__((weak, alias("default_handler")));;
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));;
extern unsigned int _text_end;

    extern unsigned int _s_data;
    extern unsigned int _e_data;
    extern unsigned int _s_bss;
    extern unsigned int _e_bss;
static unsigned long stack_top[256];



void (*const vectors[])() __attribute__((section(".vectors"))) =
{
    (void (*)())(stack_top + sizeof(stack_top)),
    &reset_handler,
    &NMI_handler,
    &h_fault_handler,
    &mm_fault_handler,
    &bus_fault,
    &usage_fault_handler
};

void reset_handler(void)
{
    

    unsigned int datasize = (unsigned char *)&_e_data - (unsigned char *)&_s_data;

    unsigned char *src = (unsigned char *)&_text_end;
    unsigned char *dst = (unsigned char *)&_s_data;
    int i;
    for (i = 0; i < datasize; i++)
    {
        *((unsigned char *)dst++) = *((unsigned char *)src++);
    }

    unsigned int bsssize = (unsigned char *)&_e_bss - (unsigned char *)&_s_bss;
    dst= (unsigned char *)&_s_bss;
    for (i = 0; i < bsssize; i++)
    {
        *((unsigned char *)dst++) = (unsigned char)0;
    }

    main();
}
