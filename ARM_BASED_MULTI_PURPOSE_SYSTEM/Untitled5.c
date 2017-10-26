#include<stdio.h>

int main()
{
int numforb=12;
int rem[50];
int base=2;
int i=0;
int j=0;

while (numforb != 0)
    {
        
		rem[i++] = numforb % base;
        numforb = numforb/base;
    }
    
    
for(j = i -1 ;j> 0;j--)

         printf("%d",rem[j]);

return 0;

}

