/*
============================================================================
Name : 32c.c
Author : Swarnendu Sekhar Das
Description : Write a program to implement semaphore to protect any critical section.
                c. protect multiple pseudo resources ( may be two) using counting semaphore

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void P(int semid) { 
    struct sembuf op = {0, -1, 0}; 
    semop(semid, &op, 1); 
}

void V(int semid) { 
    struct sembuf op = {0, 1, 0}; 
    semop(semid, &op, 1); 
}

int main() {
    key_t key = ftok(".", 'h');
    int semid = semget(key, 1, IPC_CREAT | 0666);
    semctl(semid, 0, SETVAL, 2);  

    for (int i = 0; i < 4; i++) {  
        if (fork() == 0) {
            P(semid);
            printf("Process %d acquired resource\n", getpid());
            sleep(1);
            V(semid);
            printf("Process %d released resource\n", getpid());
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) wait(NULL);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 32c.c -o 32c
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./32c
Process 8189 acquired resource
Process 8190 acquired resource
Process 8189 released resource
Process 8190 released resource
Process 8191 acquired resource
Process 8192 acquired resource
Process 8191 released resource
Process 8192 released resource
*/