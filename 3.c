/*
============================================================================
Name : 3.c
Author : Swarnendu Sekhar Das
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){

    struct rlimit limit;

    limit.rlim_cur = 5;
    limit.rlim_max = 10;

    int a = setrlimit(RLIMIT_CPU, &limit);

    if(a == 0){
        printf("New CPU time is :\nSoft limit = %ld seconds, Hard limit = %ld seconds\n", limit.rlim_cur, limit.rlim_max);
    }

    for(;;)

return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 3.c -o 3
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./3
New CPU time is :
Soft limit = 5 seconds, Hard limit = 10 seconds
*/