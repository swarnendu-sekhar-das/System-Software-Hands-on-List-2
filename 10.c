/*
============================================================================
Name : 10.c
Author : Swarnendu Sekhar Das
Description : Write a separate program using sigaction system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE

Date: 23rd Sep, 2025.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
    if (sig == SIGSEGV || sig == SIGFPE) {
        exit(1);
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;    

    int *p = NULL; 
    *p = 0;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction SIGSEGV");
    }
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction SIGINT");
    
    }

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction SIGFPE");
    }

    
    //int x = 1 / 0;

    printf("Handlers set. Test SIGINT with Ctrl-C.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 10.c -o 10
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./10
Caught signal 11
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 10.c -o 10
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./10
Segmentation fault (core dumped)
*/