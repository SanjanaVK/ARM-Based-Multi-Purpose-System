#include<stdio.h>
#include<stdlib.h>

typedef struct CircularBuffer
{
	int *head;
	int *tail;
    size_t size;
    size_t num_items;
	int *buffer;
}CB;

void additem(struct CircularBuffer *CcBuffer, int data);
int main()
{
	struct CircularBuffer *CBuffer;
	CBuffer->size=5;
	CBuffer->num_items=0;
	CBuffer->head=0;
	//printf("%d", CBuffer->size);
	int num=5;
	additem(&CBuffer,num);
	return 0;
}

void additem(struct CircularBuffer *CcBuffer, int data)
{
   // printf("%d",CcBuffer->head);
    printf("%d",CcBuffer->num_items);
    
   // if((CBuffer->head)==(CBuffer->num_items))
    {
        *CcBuffer->head=data;
       // printf("%d",data);
       // printf("%d",*CBuffer->head);
    }
      //  CBuffer->head++;
   // *CBuffer->head=5;
  // printf("%d",*CBuffer->head);
    //printf("%d",data);
}
