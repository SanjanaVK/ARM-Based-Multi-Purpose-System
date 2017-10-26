
#include<stdio.h>
#include<stdint.h>

int main()
{
uint8 buf[] = {0, 1, 10, 11};
char str;

printf("%s\n", str);
int i;
char* buf_str = (char*) malloc (2*size + 1);
char* buf_ptr = buf_str;
for (i = 0; i < size; i++)
{
    buf_ptr += sprintf(buf_ptr, "%02X", buf[i]);
}
sprintf(buf_ptr,"\n");
*(buf_ptr + 1) = '\0';
printf("%s\n", buf_str);
return 0;
}
