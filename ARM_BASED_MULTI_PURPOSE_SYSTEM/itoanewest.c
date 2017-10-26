#include<stdio.h>
#include<stdint.h>

int8_t* itoa(int32_t num, int8_t* str, int32_t base);

int32_t main()
{ 
    char str[100];
	itoa(-1,str,2);
	return 0;
	
}

void reverse(int8_t *str, int32_t length)
{
    int32_t start = 0;
    int32_t end = length -1;
    while (start < end)
    {
        int8_t temp= *(str+start);
		*(str+start)= *(str+end);
        *(str+end)=temp;
		start++;
        end--;
    }
}
 
// Implementation of itoa()
int8_t* itoa(int32_t num, int8_t* str, int32_t base)
{
    int32_t i = 0;
    int32_t neg=0;
 
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    printf("the number is:%d\n",num);
    if (num ==0)
    {
        *str='0';
        i++;
		*(str+i)='\0';
        printf("The string is:%s",str);
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if(num<0 && base==16) 
    {
    //char hex[100]="";
    //hex will hold the hexadecimal notation
    sprintf(str,"%X",num); // convert decimal to hexadecimal 

    // show the result 
    printf("converting %d to hexadecimal notation %s\n",num,str);
    return str;
	}
	
	if(num<0 && base==8) 
    {
    	//char octal[100]="";
    //octal will hold the octal notation 
    sprintf(str,"%o",num); //convert decimal to octal  
    printf("converting %d to octal notation %s\n",num,str);
    return str;
	}
    
    if (num < 0 && (base == 10 || base==2))
    {
        neg = 1;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int32_t rem = num % base;
        *(str+i)= (rem > 9)? (rem-10) + 'a' : rem + '0';
        i++;
        num = num/base;
    }
    
    // If number is negative, append '-'
    if (neg==1)
    {
        *(str+i)= '-';
        i++;
    }
 
    *(str+i)= '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
    printf("The string is:%s",str);
 
    return str;
}
 
