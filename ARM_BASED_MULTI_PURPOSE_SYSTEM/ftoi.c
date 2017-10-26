// C program for implementation of ftoa()
#include<stdio.h>
#include<math.h>
#include<stdint.h>
 
  

// reverses a string 'str' of length 'length'
void reverse(int8_t *str, int32_t length)
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
// Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int intToStr(int32_t x, int8_t str[], int32_t d, int32_t negative)
{
    int32_t i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }
 
    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
      if(negative==1)
        {
			str[i++]='-';
		}
 
    reverse(str, i);
    str[i] = '\0';
    return i;
}
 
 
// Converts a floating point number to string.
void ftoa(float n, int8_t *res, int32_t afterpoint)
{
  int32_t neg=0;
    if(n<0)
    {	
	     n=-n;
    	neg=1;
			}
			// Extract integer part
    int32_t ipart = (int32_t)n;
 
    // Extract floating part
    float fpart = n - (float)ipart;
 
    // convert integer part to string
    int32_t i = intToStr(ipart, res, 0,neg);
    neg=0;
 
    // check for display option after point
    if (afterpoint != 0)
    {
        *(res+i) = '.';  // add dot
 
        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);
 
        intToStr((int)fpart, res + i + 1, afterpoint,neg);
        //printf("neg is ftoi =%d",neg);
    }
}


 // driver program to test above funtion
int main()
{
    int8_t res[20];
    float n = -45.67448;
    
    ftoa(n, res, 3);
    printf("\n\"%s\"\n", res);
    return 0;
}
