#include<stdio.h>
#include<stdint.h>

void dump_memory(uint8_t *start, uint32_t length);

int main()
{
	
	char buf[10]={"ABCD"};
	dump_memory(buf,2
	);
	return 0;

}

void dump_memory(uint8_t *start, uint32_t length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%x \t",*(start+i));
	
	
	}
	
}


