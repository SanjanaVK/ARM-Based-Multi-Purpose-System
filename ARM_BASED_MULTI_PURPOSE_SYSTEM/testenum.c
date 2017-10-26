#include<stdio.h>

#define MAX_ITEMS    10                        //Declare maximum items in the buffer as 10
typedef struct circularbuffer                  //Declaring and Defining the structure
{
    int     first;                             // this is where i can read items from
    int     last;                              //at this location i can write items
    int     validItems;                        //current number of items
    int     data[MAX_ITEMS];                   // buffer to store the items
} circularbuffer_t;

enum states                                    //declaration of enum states
{
	bufferfull,                                //if the buffer is full
	bufferempty,                               //if the buffer is empty
	BuffernotEmpty,                            // if the buffer is not empty
	BuffernotFull,                             // if the buffer is not full
}states_e;

void initializeQueue(circularbuffer_t *Buffer);

enum states isEmpty(circularbuffer_t *Buffer);

enum states isFull(circularbuffer_t *Buffer);

enum states putItem(circularbuffer_t *Buffer, int theItemValue);

enum states getItem(circularbuffer_t *Buffer, int *theItemValue);

void printQueue(circularbuffer_t *Buffer);

void initializeQueue(circularbuffer_t *Buffer)
{
    int i;
    Buffer->validItems  =  0;
    Buffer->first       =  0;
    Buffer->last        =  0;
    for(i=0; i<MAX_ITEMS; i++)
    {
        Buffer->data[i] = 0;
    }        
    return;
}


enum states isEmpty(circularbuffer_t *Buffer) //function to check if the buffer is empty
{
    if(Buffer->validItems==0)                  //if current number of items in the buffer is zero then it is empty
        return bufferempty;
    else
        return BuffernotEmpty;                //else it is not empty
}

enum states isFull(circularbuffer_t *Buffer)    // function to  check if the buffer is full
{
	if(Buffer->validItems>=MAX_ITEMS)           //if current numbers of items is greater than or equal to ,maximum no. of items buffer is full
         return bufferfull;
    else
        return BuffernotFull;                  // else buffer is not full
    
}

enum states putItem(circularbuffer_t *Buffer, int theItemValue) //function to add an item to the buffer
{
     if(Buffer->validItems>=MAX_ITEMS)               //checks if the buffer is full before adding
    {
        printf("The Buffer is full\n");
        return bufferfull;
    }
    else
    {
        Buffer->validItems++;                           //increments the no . of items in the buffer
        Buffer->data[Buffer->last] = theItemValue;       //writes the item to data buffer in index last
        Buffer->last = (Buffer->last+1)%MAX_ITEMS;                //increments the index while adding each item and wraps around.
}

enum states getItem(circularbuffer_t *Buffer, int *theItemValue)   //function to remove item or get item
{
    if(Buffer->validItems==0)                       //if there no items in the buffer to remove, then the buffer is empty. displays an error
      printf("Buffer is empty");
        return bufferempty;
    
    else
    {
        *theItemValue=Buffer->data[Buffer->first];           //Takes the first data added, and puts it in the item value.
        Buffer->first=(Buffer->first+1)%MAX_ITEMS;           //increments first position by one to next removable item
        Buffer->validItems--;                               // decrements the no. of items in the buffer
        //return(0);
    }
}

void printQueue(circularbuffer_t *Buffer)
{
    int aux, aux1;
    aux  = Buffer->first;
    aux1 = Buffer->validItems;
    while(aux1>0)
    {
        printf("Element #%d = %d\n", aux, Buffer->data[aux]);
        aux=(aux+1)%MAX_ITEMS;
        aux1--;
    }
    return;
}


int main(void)
{
    int i;
    int readValue;
    circularbuffer_t Buffer;
    
    initializeQueue(&Buffer);
    for(i=0; i<MAX_ITEMS+1; i++)
    {
        putItem(&Buffer, i);
        //printf("writeValue = %d\n", Buffer.data[Buffer.last]);
    }
    printQueue(&Buffer);
    
    for(i=0; i<(MAX_ITEMS-8); i++)
    {
        getItem(&Buffer, &readValue);
        printf("readValue = %d\n", readValue);
    }
    printQueue(&Buffer);
    return 0;
    //exit(0);
}
