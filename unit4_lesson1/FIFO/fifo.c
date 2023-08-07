/*
 * fifo.c
 *
 *  Created on: Aug 3, 2023
 *      Author: AHMED BADRY
 */
#include "fifo.h"


fifo_status fifo_enq(fifo_buf_t* fifo,element_type item)
{
	if(!fifo->base||!fifo->tail||!fifo->head)
		return FIFO_NULL;
	if(fifo_is_full(fifo)==FIFO_FULL)
		return FIFO_FULL;
	*(fifo->head)=item;
	fifo->count++;
	if(fifo->head==(fifo->base+fifo->length*sizeof(element_type)))
	fifo->head=fifo->base;
	else
		fifo->head++;
	return FIFO_NOERROR;

}
fifo_status fifo_deq(fifo_buf_t* fifo,element_type* item)
{
	if(!fifo->base||!fifo->tail||!fifo->head)
		return FIFO_NULL;
	if(fifo->count==0)
		return FIFO_EMPTY;
	*item=*(fifo->tail);
	fifo->count--;
	if(fifo->tail==(fifo->base+fifo->length*sizeof(element_type)))
	fifo->tail=fifo->base;
	else
		fifo->tail++;
	return FIFO_NOERROR;

}
fifo_status fifo_init(fifo_buf_t* fifo,element_type* buf,int length)
{
	if(buf==NULL)
		return FIFO_NULL;
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->length=length;
	fifo->count=0;
	return FIFO_NOERROR;
}
fifo_status fifo_is_full(fifo_buf_t* fifo)
{
	if(!fifo->base||!fifo->tail||!fifo->head)
		return FIFO_NULL;
	if(fifo->count==fifo->length)
		return FIFO_FULL;
	return FIFO_NOERROR;


}
void fifo_print(fifo_buf_t*fifo)
{
	element_type*temp;
	int i;
	if(fifo->count==0)
		printf("fifo is empty\n");
	else
	{
		temp=fifo->tail;
		printf("\t=========fifo print=======\n");
		for(i=0;i<fifo->count;i++)
		{
			printf("\t%d\n",*temp);
			temp++;
		}
		printf("\t=================\n");
	}
}


