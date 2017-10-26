
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

char* itoa(int num, char* str, int base);

int main()
{ 
    char str[100];
	itoa(-10,str,2);
	/*int j=0;
	while(*(str+j)!='\0')
	{*/
	//printf("%s:"str);
	/*j++;
	str++;
    }*/
	return 0;
	
}

void reverse(char *str, int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        char temp= *(str+start);
		*(str+start)= *(str+end);
        *(str+end)=temp;
		start++;
        end--;
    }
}
 
// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    int neg=0;
    int negforB=0;
    int numforb=0;
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
	
	 if (num < 0 && base == 2)
    {
        negforB = 1;
    }
	
    
    if (num < 0 && base == 10)
    {
        neg = 1;
        num = -num;
    }
 
    
    printf("negforb is %d\n",negforB);
    if(negforB==1)
    {
    	int numbforb=-num;
	    int rem[50];
        int i=0;
        int j=0;
        int length=0;
        printf("number is %d\n",numbforb);
    
	    while (numforb != 0)
    {

        printf("number is %d\n",numbforb);
		int rem = numforb % base;
        *(str+i)= (rem > 9)? (rem-10) + 'a' : rem + '0';
        i++;
        numforb = numforb/base;
        printf("eachtime numforb:%d\n",numforb);
        length++;
        
    }
    printf("length is:%d",length);
    printf("string before is is:%s",str);
     char str[length+1], onesComp[length+1], twosComp[length+1];
     int z, carry=1;
     /*
     * Finds the 1's complement of the binary number
     */
    for(z=0; z<length; z++)
    {
        if(str[z]=='1')
        {
            onesComp[z] = '0';
        }
        else if(str[z]=='0')
        {
            onesComp[z] = '1';
        }
    }
    onesComp[length] = '\0';
 
    /*
     * Adds 1 to the 1's complement of the binary number to get 2's complement
     */
    for(z=length-1; z>=0; z--)
    {
        if(onesComp[z]=='1' && carry==1)
        {
            twosComp[z] = '0';
        }
        else if(onesComp[z]=='0' && carry==1)
        {
            twosComp[z] = '1';
            carry = 0;
        }
        else
        {
            twosComp[z] = onesComp[z];
        }
    }
    twosComp[32] = '\0';
 
    printf("\nOriginal binary value = %s\n", str);
    printf("One's complement = %s\n", onesComp);
    printf("Two's complement = %s", twosComp);
 
    return str;
}

     // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
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
 
