#include <stdint.h>
extern  unsigned  int stack_top ;

extern int main(void);

void reset_handler(void);

void default_handler(void)
{
    reset_handler();
}

void NMI_handler(void) __attribute__((weak, alias("default_handler")));
void h_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mm_fault_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));

uint32_t vectors[] __attribute__((section(".vectors"))) = {
    (uint32_t)&stack_top ,
    (uint32_t)&reset_handler,
    (uint32_t)&NMI_handler,
    (uint32_t)&h_fault_handler,
    (uint32_t)&mm_fault_handler,
    (uint32_t)&bus_fault,
    (uint32_t)&usage_fault_handler
};


void reset_handler(void)
{


extern unsigned int _text_end;
extern unsigned int _s_data;
extern unsigned int _e_data;
extern unsigned int _s_bss;
extern unsigned int _e_bss;








unsigned int datasize= (unsigned char*) &_e_data - (unsigned char*) &_s_data;

unsigned int *src= (unsigned char*) &_text_end;
unsigned int *dst= (unsigned char*) &_s_data;
int i;
for(i=0;i<datasize;i++)
{
*((unsigned char*)dst++)=*((unsigned char*)src++);
}
unsigned int bsssize= (unsigned char*) &_e_bss - (unsigned char*) &_s_bss;
dst= (unsigned char*) &_s_bss;
for(i=0;i<bsssize;i++)
{
*((unsigned char*)dst++)= (unsigned char) 0;
}


    main();
}