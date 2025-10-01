/*
============================================================================
Name : 9.c
Author : Swarnendu Sekhar Das
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
              signal - Use signal system call.

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigintHandler(int signal) {
    printf("SIGINT is ignored for now...\n");
}

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is ignored. Please wait for 10 seconds \n");

    sleep(10);

    printf("Now resetting SIGINT. Press Ctrl+C to terminate.\n");
    signal(SIGINT, SIG_DFL);

    sleep(10);

    
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 9.c -o 9
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./9
SIGINT is ignored. Please wait for 10 seconds 
Now resetting SIGINT. Press Ctrl+C to terminate.
*/