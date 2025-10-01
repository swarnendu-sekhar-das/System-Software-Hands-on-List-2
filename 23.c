/*
============================================================================
Name : 23.c
Author : Swarnendu Sekhar Das
Description : Write a program to print the maximum number of files can be opened within a process and
              size of a pipe (circular buffer).

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main() {
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Max open files: %llu\n", (unsigned long long)rl.rlim_cur);

    int fldes[2];
    pipe(fldes);
    long pipe_size = fpathconf(fldes[0], _PC_PIPE_BUF);
    printf("Pipe buffer size: %ld\n", pipe_size);
    close(fldes[0]);
    close(fldes[1]);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 23.c -o 23
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./23
Max open files: 1024
Pipe buffer size: 4096
*/