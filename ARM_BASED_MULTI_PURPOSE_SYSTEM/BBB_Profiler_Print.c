
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "string.h"

int BBB_print_profiler(void)
{
int i;
uint8_t src[5000], dst[5000];
struct timeval my_print1_start,my_print1_end,my_print2_start, my_print2_end, my_print3_start, my_print3_end,my_print4_start,my_print4_end;
long time,mtime, secs, usecs;
int32_t x=1234;
float y=12.34;
char str[100]="Test";
int32_t length=10;
gettimeofday(&my_print1_start, NULL);
printf("TESTCHARACTERSPRINTUSINGPROFILER");
gettimeofday(&my_print1_end, NULL);
secs  = my_print1_end.tv_sec  - my_print1_start.tv_sec;
usecs = my_print1_end.tv_usec - my_print1_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of 20 characters: %ld usec\n", time);

gettimeofday(&my_print2_start, NULL);
printf("%d\n",x);
gettimeofday(&my_print2_end, NULL);
secs  = my_print2_end.tv_sec  - my_print2_start.tv_sec;
usecs = my_print2_end.tv_usec - my_print2_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of one character: %ld usec\n", time);

gettimeofday(&my_print2_start, NULL);
printf("%d\n",x);
gettimeofday(&my_print2_end, NULL);
secs  = my_print2_end.tv_sec  - my_print2_start.tv_sec;
usecs = my_print2_end.tv_usec - my_print2_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of one variable: %ld usec\n", time);

gettimeofday(&my_print3_start, NULL);
printf("%d\t%f\n",x,y);
gettimeofday(&my_print3_end, NULL);
secs  = my_print3_end.tv_sec  - my_print3_start.tv_sec;
usecs = my_print3_end.tv_usec - my_print3_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of two variables: %ld usec\n", time);

gettimeofday(&my_print4_start, NULL);
printf("%d\t%f\t,%s\n",x,y,str);
gettimeofday(&my_print4_end, NULL);
secs  = my_print4_end.tv_sec  - my_print4_start.tv_sec;
usecs = my_print4_end.tv_usec - my_print4_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for printf of three variables: %ld usec\n", time);

return 0;
}


