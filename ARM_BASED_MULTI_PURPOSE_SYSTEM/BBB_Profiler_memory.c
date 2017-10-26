#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "memory.h"
#include "string.h"

int BBB_profiler(void)
{
int i;
uint8_t src[5000], dst[5000];
struct timeval my_memmove_start,my_memmove_end,memmove_start,memmove_end,my_memzero_start,my_memzero_end,memset_start,memset_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
//int32_t x=1234;
//float y=12.34;
//char str[100]="Test";
int32_t length=10;
gettimeofday(&my_memmove_start, NULL);
my_memmove(src,dst,length);
//printf("%d\t%f\t%d\n",x,y,y);
gettimeofday(&my_memmove_end, NULL);
//printf("endinsecs is:%ld\t", end.tv_sec);
secs  = my_memmove_end.tv_sec  - my_memmove_start.tv_sec;
usecs = my_memmove_end.tv_usec - my_memmove_start.tv_usec;
time = ((secs*1000000)+usecs); 
//printf("Elapsed time for printf of with three  variable: %ld usec\n", time);
printf("Elapsed time for my_memove for %d bytes: %ld usec\n", length,time);

gettimeofday(&memmove_start, NULL);
memmove(src,dst,length);
gettimeofday(&memmove_end, NULL);
secs  = memmove_end.tv_sec  - memmove_start.tv_sec;
usecs = memmove_end.tv_usec - memmove_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for memmove for %d bytes: %ld usec\n", length,time);

gettimeofday(&my_memzero_start,NULL);
my_memzero(src,length);
gettimeofday(&my_memzero_end, NULL);
secs  = my_memzero_end.tv_sec  - my_memzero_start.tv_sec;
usecs = my_memzero_end.tv_usec - my_memzero_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for my_memzero for %d bytes: %ld usec\n", length,time);

gettimeofday(&memset_start,NULL);
memset(src,0,length);
gettimeofday(&memset_end, NULL);
secs  = memset_end.tv_sec  - memset_start.tv_sec;
usecs = memset_end.tv_usec - memset_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for memset for %d bytes: %ld usec\n", length,time);

gettimeofday(&my_reverse_start,NULL);
my_reverse(src,0,length);
gettimeofday(&my_reverse_end,NULL);
secs  = my_reverse_end.tv_sec  - my_reverse_start.tv_sec;
usecs = my_reverse_end.tv_usec - my_reverse_start.tv_usec;
time = ((secs*1000000)+usecs); 
printf("Elapsed time for my_reverse for %d bytes: %ld usec\n", length,time);


return 0;
}
