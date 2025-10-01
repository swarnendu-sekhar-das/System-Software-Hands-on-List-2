/*
============================================================================
Name : 32b.c
Author : Swarnendu Sekhar Das
Description : Write a program to implement semaphore to protect any critical section.
                b. protect shared memory from concurrent write access

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void P(int semid) 
{ 
    struct sembuf op = {0, -1, 0}; 
    semop(semid, &op, 1); 
}
void V(int semid) { 
    struct sembuf op = {0, 1, 0}; 
    semop(semid, &op, 1); 
}

int main() {
    key_t sem_key = ftok(".", 'f');
    int semid = semget(sem_key, 1, IPC_CREAT | 0666);
    semctl(semid, 0, SETVAL, 1);

    key_t shm_key = ftok(".", 'g');
    int shmid = shmget(shm_key, 1024, IPC_CREAT | 0666);
    char *data = (char *)shmat(shmid, NULL, 0);

    int pid = fork();
    if (pid == 0) {
        P(semid);
        strcat(data, "Child wrote ");
        V(semid);
    } else {
        P(semid);
        strcpy(data, "Parent wrote ");
        V(semid);
        wait(NULL);
        printf("Shared data: %s\n", data);
    }
    shmdt(data);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 32b.c -o 32
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 32b.c -o 32b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./32b
Shared data: Parent wrote Child wrote 
*/