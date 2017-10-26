#include<stdio.h>
int main()
{
	int dec;
	printf("enter the decimal");
	scanf("%d",&dec);
	char str[50];
	int base=2;
	int i=0;
	int z=0;
	int length=0;
	int num=dec;
	int rem[50];
	
	 while (num != 0)
    {
        rem[i++] = num % base;
        
        num = num/base;
    }
    print("length is:%d",rem);
    printf("length is:%d",i);
    length=i;
    
    print("number is %d",dec);
    
    if(dec<0)
    {
	
    printf("string before is is:%s",str);
     int onesComp[length+1], twosComp[length+1];
     int z, carry=1;
     /*
     * Finds the 1's complement of the binary number
     */
    for(z=0; z<length; z++)
    {
        if(str[z]==1)
        {
            onesComp[z] = 0;
        }
        else if(str[z]==0)
        {
            onesComp[z] = 1;
        }
    }
    //onesComp[length] = '\0';
 
    /*
     * Adds 1 to the 1's complement of the binary number to get 2's complement
     */
    for(z=length-1; z>=0; z--)
    {
        if(onesComp[z]==1 && carry==1)
        {
            twosComp[z] = 0;
        }
        else if(onesComp[z]==0 && carry==1)
        {
            twosComp[z] = 1;
            carry = 0;
        }
        else
        {
            twosComp[z] = onesComp[z];
        }
    }
    //twosComp[length] = '\0';
 
    printf("\nOriginal binary value = %d\n", str);
    printf("One's complement = %d\n", onesComp);
    printf("Two's complement = %d", twosComp);
 
}
    printf("the string is:%d",str);
    
	return 0;
}
