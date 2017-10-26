#include <stdio.h>
#include <stdint.h>


uint32_t little_to_big(uint32_t data);

int main()
{
   int x;
   int num;
   printf("Enter a 32 bit number:\t");
   scanf("%x",&num);
   x=num;
   little_to_big(x);
   
}

uint32_t little_to_big(uint32_t data)
{
   int z = 1;

  char *y = (char*)&z;

  printf("The value in  lower memory is:%c\n",*y+48);   
  
   if((*y+48)=='1')
   {
   
        data = ( data >> 24 ) | (( data << 8) & 0x00ff0000 )| ((data >> 8) & 0x0000ff00) | ( data << 24)  ; 

        printf("value = %x", data); 
   }

}

