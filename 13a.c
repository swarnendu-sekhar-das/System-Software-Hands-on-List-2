/*
============================================================================
Name : 13a.c
Author : Swarnendu Sekhar Das
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not.

Date: 23rd Sep, 2025.
============================================================================
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <bits/sigaction.h>
#include <stdlib.h>

void catch (int sig)
{
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main()
{
    printf("PID (Reciever): %d\n", getpid());

    struct sigaction sa;

    sa.sa_handler = catch;
    for (;;)
    {
        sigaction(SIGSTOP, &sa, NULL);
    }
    return (0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 13a.c -o 13a
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./13a
PID (Reciever): 14162

[1]+  Stopped                 ./13a
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$  
*/