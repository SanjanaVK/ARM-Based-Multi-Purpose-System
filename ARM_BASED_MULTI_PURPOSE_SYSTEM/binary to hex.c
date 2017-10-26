
 
 #include <stdio.h>
#include <string.h>

int main(void) {
	
	//dump_memory(*start,len);
	char *bin="1111";
	char *a = bin;
	int num = 0;
	
do {
    int b = *a=='1'?1:0;
    num = (num<<1)|b;
    a++;
} while (*a);
printf("%X\n", num);
}



 
