/*
============================================================================
Name : 19.c
Author : Naman Samant
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
int main() {
    	uint64_t st, end;
	st = __builtin_ia32_rdtsc();
	getpid();
	end = __builtin_ia32_rdtsc();
	uint64_t cycles = end - st;
	printf("Cycles taken to execute getpid system call: %lu\n", cycles);
	return 0;
}
