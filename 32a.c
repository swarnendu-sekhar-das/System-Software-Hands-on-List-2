/*
============================================================================
Name : 32a.c
Author : Swarnendu Sekhar Das
Description : Write a program to implement semaphore to protect any critical section.
                a. rewrite the ticket number creation program using semaphore

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
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
    key_t sem_key = ftok(".", 'd');
    int semid = semget(sem_key, 1, IPC_CREAT | 0666);
    semctl(semid, 0, SETVAL, 1);

    key_t shm_key = ftok(".", 'e');
    int shmid = shmget(shm_key, sizeof(int), IPC_CREAT | 0666);
    int *ticket = (int *)shmat(shmid, NULL, 0);
    *ticket = 0;

    pid_t pid = fork();
    for (int i = 0; i < 5; i++) {
        P(semid);
        (*ticket)++;
        printf("Ticket: %d (PID %d)\n", *ticket, getpid());
        V(semid);
    }

    if (pid != 0) wait(NULL);
    shmdt(ticket);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 32a.c -o 32a
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./32a
Ticket: 1 (PID 8065)
Ticket: 2 (PID 8066)
Ticket: 3 (PID 8065)
Ticket: 4 (PID 8066)
Ticket: 5 (PID 8065)
Ticket: 6 (PID 8066)
Ticket: 7 (PID 8065)
Ticket: 8 (PID 8066)
Ticket: 9 (PID 8065)
Ticket: 10 (PID 8066)
*/