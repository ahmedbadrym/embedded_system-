/*
 * author:ahmed badry
 * lifo.h
 * augest 2023
 */
#include "lifo.h"

lifo_status lifo_add(lifo_buf_t* buf,unsigned int item)
{
	//check valid
if (!buf->base|| !buf->head)
	return LIFO_NULL ;
//check full
if(buf->head >=(buf->base+(buf->length *4)))
	return LIFO_FULL;
*(buf->head)=item;
buf->head++;
buf->count++;
return LIFO_NOERROR ;

}

lifo_status lifo_get(lifo_buf_t* buf,unsigned int* item)
{
	//check valid
	if (!buf->base|| !buf->head)
		return LIFO_NULL ;
	//check lifo empty?
	if(buf->count==0)
		return LIFO_EMPTY ;
	buf->head--;
	*item=*(buf->head);
	buf->count--;
	return LIFO_NOERROR ;
}

lifo_status lifo_init(lifo_buf_t* buf,unsigned int* arr,int length)

{
	if(arr== NULL)
		return LIFO_NULL;
	buf->base=arr;
	buf->head=arr;
	buf->length=length;
	buf->count=0;
	return LIFO_NOERROR;
}
