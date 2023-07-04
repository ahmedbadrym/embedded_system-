#include "uart.h"
#define uartd  *((volatile unsigned int *)((unsigned int *) 0x101f1000))
void send (unsigned char *x){
while(*x !='\0'){
uartd=(unsigned int)(*x);
x++;}}     