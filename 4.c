/*
============================================================================
Name : 4.c
Author : Swarnendu Sekhar Das
Description : Write a program to measure how much time is taken to execute 100 getppid() system call. Use time stamp counter.

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h> 

uint64_t rdtsc() {
    unsigned int lo, hi;
    
    __asm__ __volatile__ (
        "rdtsc"
        : "=a" (lo), "=d" (hi) 
    );
    return ((uint64_t)hi << 32) | lo;
}

int main(){

 int start, end;
 
 start = rdtsc();
 
 for(int i = 1; i <= 100; i++){
    getppid();
 }
 
 end = rdtsc();
 
 printf("Total cycles taken for 100 getppid(): %d", end - start);
 
 return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 4.c -o 4
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./4
Total cycles taken for 100 getppid(): 153520
*/