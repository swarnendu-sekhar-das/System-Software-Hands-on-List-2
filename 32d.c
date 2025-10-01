/*
============================================================================
Name : 32d.c
Author : Swarnendu Sekhar Das
Description : Write a program to implement semaphore to protect any critical section.
                d. remove the created semaphore

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main() {
    key_t key = ftok(".", 'd');  
    int semid = semget(key, 1, 0666);
    semctl(semid, 0, IPC_RMID);
    printf("Semaphore Removed\n");
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 32d.c -o 32d
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./32d
Semaphore Removed
*/