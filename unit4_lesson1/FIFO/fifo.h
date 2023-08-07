/*
 * fifo.h
 *
 *  Created on: Aug 3, 2023
 *      Author: AHMED BADRY
 */
#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"

#define element_type uint32_t
#define width 5
element_type buf1[width];
//typedef
typedef struct{
	element_type* base;
	element_type* tail;
	element_type* head;
	unsigned int length;
	unsigned int count;

}fifo_buf_t;
typedef enum{
	FIFO_NOERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}fifo_status;

//APIS
fifo_status fifo_enq(fifo_buf_t* fifo,element_type item);
fifo_status fifo_deq(fifo_buf_t* fifo,element_type* item);
fifo_status fifo_init(fifo_buf_t* fifo,element_type* buf,int length);
fifo_status fifo_is_full(fifo_buf_t* fifo);
void fifo_print(fifo_buf_t*fifo);



#endif
