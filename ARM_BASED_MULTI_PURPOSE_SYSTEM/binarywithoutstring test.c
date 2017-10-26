#include<stdio.h>


int main()
{
	

    long int decimalNumber,remainder,quotient;

    int binaryNumber[100],i=1,j;


    printf("Enter any decimal number: ");

    scanf("%ld",&decimalNumber);


    quotient = decimalNumber;


    while(quotient!=0){

         binaryNumber[i++]= quotient % 2;

         quotient = quotient / 2;

    }


    printf("Equivalent binary value of decimal number %d: ",decimalNumber);

    for(j = i -1 ;j> 0;j--)

         printf("%d",binaryNumber[j]);
         
         int BinaryNumber1[100];
         for(i=0;i<31;i++)
         {
         	BinaryNumber1[i]=(binaryNumber[j]||0);
		 }
		  for(j =0;j>31;j++)

         printf("%d",BinaryNumber1[j]);


    return 0;

}

