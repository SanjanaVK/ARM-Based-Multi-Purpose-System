#include<stdio.h>
#include<stdint.h>


#define MAX_Length 10
typedef struct
{
    uint32_t length;
    uint8_t data[MAX_Length];   // buffer structure; containing head tail and base address of the buffer
    uint8_t *buff;
    uint8_t *head;
    uint8_t *tail;
    uint32_t new_len;

}cirbuf_t;

typedef enum {buf_full , buf_empty, buf_not_full, buf_not_empty, add_success, remove_success,add_success_with_wrap_around} state;

typedef enum
{
success,
failure}teststate_t;

state status;
cirbuf_t test_buffer;

uint8_t* initialize(cirbuf_t *cb)
{

	cb=malloc(sizeof(cirbuf_t));
    return cb->buff;
}

void destroy(cirbuf_t *cb)
{
	free(cb);
}


state buff_full(cirbuf_t *cb)  // Function checks if the buffer is full or not
{
    if (cb->new_len == cb->length)
    {   // If the head is at the end of the buffer and tail is at the start then buffer is full
        //or if head is one position behind the tail then also buffer is full
        return buf_full;
    }
    else
    {
    //rintf("
        return buf_not_full;
    }

}

state buff_empty(cirbuf_t *cb)
{
    // if head and tail of the buffer are at the same position then that means buffer is empty.
    if(cb->new_len==0)
    {
        return buf_empty;
    }
    else
    {
        return buf_not_empty;
    }
}

state add_data(cirbuf_t *cb, uint8_t item)
{
    state error_code;
    error_code=buff_full(cb);  // before adding new item it checks if buffer is full or not
    if(error_code==buf_not_full)
    {
        if(cb->head==(cb->buff)+(cb->length)-1)
        {// if head is at the last position of the buffer then add the item there
         //and then put head at the base address of the buffer
          cb->head=cb->buff;
        *(cb->head)=item;
        (cb->new_len)++;
        return add_success_with_wrap_around;
        }

        else
        {// otherwise add the item at the location of head and then head++
            cb->head++;
            *(cb->head)=item;
            (cb->new_len)++;
            return add_success;

        }


    }
    else if(error_code==buf_full)
    { // If buffer is full , do not add item and return error
      return buf_full;
    }
}

uint8_t read_data(cirbuf_t *cb)
{
    state error_code;
	uint8_t rd;
    error_code=buff_empty(cb);  // check for buffer empty before removing item
    if(error_code==buf_not_empty)
    {

        if(cb->tail==((cb->buff)+(cb->length))-1)
        {  // if tail is at the last position of the buffer then remove the item there
         //and then put tail at the base address of the buffer

        cb->tail=cb->buff;
		rd=*(cb->tail);
        *(cb->tail)=0;
        (cb->new_len)--;
        return rd;
        }

        else
        {  // otherwise remove the item at the location of tail and then do tail++
            (cb->tail)++;
			rd=*(cb->tail);
            *(cb->tail)=0;
            (cb->new_len)--;
            return rd;

        }
    }
    else if(error_code==buf_empty)
    { // If buffer is empty , do not remove item and return error
      return buf_empty;
    }
}




teststate_t unittest_bufferfull()
{
	int32_t count=0;
while(count==MAX_Length)
{
	status=add_data(&test_buffer,count);
	count++;
}
 if(status==buf_full)
 return success;
 else 
 return failure;
}

teststate_t unittest_bufferempty()
{
	int32_t count=0;
while(count<MAX_Length)
{
	int8_t test_data[15];
	test_data[count]=read_data(&test_buffer);
	count++;
}
 status=buff_empty(&test_buffer);
 if(status==buf_empty)
 return success;
 else
 return failure;
 
}

teststate_t unittest_additemwraparound()
{
	state status;
	int32_t count=0;
 unittest_bufferfull();
 count=read_data(&test_buffer);
 status=add_data(&test_buffer,count);
 if(status=add_success_with_wrap_around)
 return success;
 else
 return failure;
}

teststate_t unittest_additemandremoveitem()
{
	uint8_t item=2,value=0;
	state test1, test2;
	test1=add_data(&test_buffer,item);
	value=read_data(&test_buffer);
	if(item==value)
	return success;
	else 
	return failure;
}

teststate_t unittest_currentitemsinadd()
{
  int32_t count=0;
  while(count<MAX_Length)
{
	add_data(&test_buffer,count);
	count++;
}
     if(test_buffer.new_len==MAX_Length)
	return success;
	else
	return failure;	
}

teststate_t unittest_removeitemwraparound()
{
	int32_t count=0;
	int32_t value;
while(count<MAX_Length)
{
	int8_t test_data[15];
	test_data[count]=read_data(&test_buffer);
	count++;
}
	add_data(&test_buffer,count);
	value=read_data(&test_buffer);
	if(count==value)
	return success;
	else
	return failure;
}

teststate_t unittest_currentitemsinremove()
{
  int32_t count=0;
  while(count<MAX_Length)
{
	read_data(&test_buffer);
	count++;
}
     if(test_buffer.new_len==0)
	return success;
	else
	return failure;	
}



int main()
{ 
    
	teststate_t result1,result2,result3,result4,result5,result6;
	test_buffer.buff= initialize(&test_buffer);
	test_buffer.head=test_buffer.data;
			 	test_buffer.tail=test_buffer.data;
			 	test_buffer.buff=test_buffer.data;
			 	test_buffer.length=MAX_Length;
			 	test_buffer.new_len= 0;
result1=unittest_bufferfull();
if(result1==success)
	 printf("CB UNIT TEST:1/7-<bufferfull> PASS\n");
else
printf("CB UNIT TEST:1/7-<bufferfull> FAIL\n"); 
result2=unittest_bufferempty();
if(result2==success)
	printf("CB UNIT TEST:2/7-<bufferempty> PASS\n");
	else
	printf("CB UNIT TEST:1/7-<bufferfull> FAIL\n");
result3=unittest_additemwraparound();
if(result3==success)
	printf("CB UNIT TEST:3/7-<additemwraparound> PASS\n");
	else
	printf("CB UNIT TEST:1/7-<bufferfull> FAIL\n");
result4=unittest_currentitemsinadd();
if(result4==success)
	printf("CB UNIT TEST:4/7-<currentitemsinadd> PASS\n");
	else
	printf("CB UNIT TEST:1/7-<bufferfull> FAIL\n");
result5=unittest_removeitemwraparound();
if(result5==success)
	printf("CB UNIT TEST:5/7-<removeitemwraparound> PASS\n");
	else
	printf("CB UNIT TEST:1/7-<bufferfull> FAIL\n");
result6=unittest_currentitemsinremove();
if(result6==success)
	printf("CB UNIT TEST:6/7-<currentitemsinremove> PASS\n");
	else
	printf("CB UNIT TEST:1/7-<bufferfull> FAIL\n");
	initialize(&test_buffer);
	if(&test_buffer)
	printf("CB UNIT TEST:7/7-<initialisation> PASS\n");
	else
	printf("CB UNIT TEST:7/7-<initialisation> FAIL\n");
	return 0;
		
}

