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
	int8_t item=2,value;
	add_data(&test_buffer,item);
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

teststate_t unittest_removeitemwraparound();
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



int main()
{
	//teststate_t result;
	teststate_t unittest_bufferfull();
	return 0;
		
}
