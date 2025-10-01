/*
============================================================================
Name : 12.c
Author : Swarnendu Sekhar Das
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
              the parent process from the child process.

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0) {  
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        sleep(2);  
        printf("Child is now orphan, New Parent PID: %d\n", getppid());
        sleep(5);    
    } 
    
    else {  
        printf("Parent PID: %d\n", getpid());
        sleep(10);
    }
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 12.c -o 12
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./12
Parent PID: 13526
Child PID: 13527, Parent PID: 13526
Killed
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ Child is now orphan, New Parent PID: 2498
*/