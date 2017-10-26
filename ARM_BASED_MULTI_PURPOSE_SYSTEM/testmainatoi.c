#include<stdio.h>
#include<string.h>

int main(void) 
{
	int i,length=0;
    char input[10];
    printf("Enter a string: ");
    gets(input);
    printf("input %s\n",input);
	    //my_atoi(input);
	    length=strlen(input);
	    for(i=0;i<length;i++)
	    {
    	printf("%d",*(input+i));
    }
    return 0;
    
}
