/*
 * author:ahmed badry
 * lifo.h
 * augest 2023
 */
#include "stdio.h"
#include "stdlib.h"
#ifndef lifo.h
#define lifo.h
//typedf
typedef struct{
	unsigned int* base;
	unsigned int length;
	unsigned int count;
	unsigned int* head;
}lifo_buf_t;
typedef enum{
	LIFO_NOERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}lifo_status;

//APIS
lifo_status lifo_add(lifo_buf_t* buf,unsigned int item);

lifo_status lifo_get(lifo_buf_t* buf,unsigned int* item);

lifo_status lifo_init(lifo_buf_t* buf,unsigned int* arr,int length);



#endif
