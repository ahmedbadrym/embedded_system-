/*
 * author:ahmed badry
 * main.c
 * augest 2023
 */
#include "stdio.h"
#include "stdlib.h"
#include "fifo.h"
//static allocation

void main(){

	element_type i,x=0;
	fifo_buf_t uart_fifo ;
	if(fifo_init(&uart_fifo,buf1,5)==FIFO_NOERROR)
		printf("init is done\n");

		for(i=0;i<7;i++)
		{
			if(fifo_enq(&uart_fifo,i)== FIFO_NOERROR)
				printf("fifo deq = %d\n",i);
			else
				printf("fifo deq failed\n");

		}
	fifo_print(&uart_fifo);

	if(fifo_deq(&uart_fifo,&x)== FIFO_NOERROR)
		printf("fifo deq = %d\n",x);
	if(fifo_deq(&uart_fifo,&x)== FIFO_NOERROR)
		printf("fifo deq = %d\n",x);
	fifo_print(&uart_fifo);

}


