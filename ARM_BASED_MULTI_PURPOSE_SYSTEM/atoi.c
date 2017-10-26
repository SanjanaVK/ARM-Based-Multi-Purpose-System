#include <stdio.h>
#include<stdint.h>

int my_atoi(char * str);

int my_atoi(char *str)
	{
		printf("string:%s\n",str);
		int i=0;
		int length=0;
		//int length=0;
		
		
		while(*(str+i)!='\0')
		//for(i=0;str[i]!='\0';i++)
		{
		    length++;
		    i++;
		}
	
		printf("length is: %d /n",length);
		for(i=0;i<length;i++)
    	{
		printf(" %d",*(str+i));
	}
	}

int main(void) 
{
	int length=0;
    char input[10];
    printf("Enter a string: ");
    gets(input);
    //printf("input %s",input);
    //length=strlen(input);
	    my_atoi(input);
    return 0;
    
}
	
	
	
	


