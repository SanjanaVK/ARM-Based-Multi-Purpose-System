#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "string.h"
#include "BBB_Profiler.h"

int main()
{
	BBB_memory_profiler(); //profiler for memory functions
	BBB_data_profiler(); // profiler for data function
	BBB_print_profiler();// profiler for printf function
	return 0;
}
