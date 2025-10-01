/*
============================================================================
Name : 13b.c
Author : Swarnendu Sekhar Das
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not.

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid;
    printf("Enter PID of process to stop\n");
    scanf("%d", &pid);

    printf("Sending SIGSTOP signal to process: %d\n", pid);
    kill(pid, SIGSTOP);

    printf("SIGSTOP signal sent\n");
 
    return (0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on Lis
t 2$ gcc 13b.c -o 13b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./13b
Enter PID of process to stop
14162
Sending SIGSTOP signal to process: 14162
SIGSTOP signal sent
*/