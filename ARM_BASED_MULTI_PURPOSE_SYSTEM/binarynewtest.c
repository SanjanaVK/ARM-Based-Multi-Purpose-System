#include<stdio.h>
#include<stdint.h>

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
int main()
    {
    	int32_t num=12;
		int base=2;
		char str[50];
	    int rem[50];
        int i=0;
        int j=0;
        int length=0;
        int testlength=0;
        int len=0;
        printf("number is %d\n",num);
    
	    while (num != 0)
    {

        printf("number is %d\n",num);
		int rem = num % base;
        *(str+i)= (rem > 9)? (rem-10) + 'a' : rem + '0';
        i++;
        num = num/base;
        printf("eachtime num:%d\n",num);
        length++;
        
    }
    printf("length is:%d",length);
    reverse(str, length);
    printf("string after reverse is %s:",str);
    testlength=31-length;
    while(testlength>=0)
    {
		*(str+testlength)='0';
    	testlength--;
	}
    printf("string before is is:%s",str);
    len=32;
    
     char onesComp[len+1], twosComp[len+1];
     int z, carry=1;
     /*
     * Finds the 1's complement of the binary number
     */
    for(z=0; z<len; z++)
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
    onesComp[len] = '\0';
 
    /*
     * Adds 1 to the 1's complement of the binary number to get 2's complement
     */
    for(z=len-1; z>=0; z--)
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
    twosComp[len] = '\0';
 
    printf("\nOriginal binary value = %s\n", str);
    printf("One's complement = %s\n", onesComp);
    printf("Two's complement = %s", twosComp);
 
    return str;
}

