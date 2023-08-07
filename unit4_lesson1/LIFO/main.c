/*
 * author:ahmed badry
 * main.c
 * augest 2023
 */
#include "stdio.h"
#include "stdlib.h"
#include "lifo.h"
//static allocation
unsigned int arr[5]={1,2,3,4,5};
void main(){
	int i,x=0;
	lifo_buf_t uart_lifo, i2c ;
	lifo_init(&uart_lifo,arr,5);

	//dynamic allocation
	unsigned int* arr2=(unsigned int*) malloc(5 * sizeof(unsigned int));
		lifo_init(&i2c,arr2,5);
		for(i=0;i<5;i++)
		{
			if(lifo_add(&uart_lifo,i)== LIFO_NOERROR)
			printf("lifo add = %d\n",i);
		}
		for(i=0;i<5;i++)
				{
			if(lifo_get(&uart_lifo,&x)== LIFO_NOERROR)
					printf("\nlifo get = %d",x);
				}









}
