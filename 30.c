/*
============================================================================
Name : 30.c
Author : Swarnendu Sekhar Das
Description : Write a program to create a shared memory.
                a. write some data to the shared memory
                b. attach with O_RDONLY and check whether you are able to overwrite.
                c. detach the shared memory
                d. remove the shared memory

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    key_t key = ftok(".", 'b');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *ptr = (char *)shmat(shmid, NULL, 0);
    strcpy(ptr, "Hello Swarnendu");
    printf("Wrote: %s\n", ptr);
    shmdt(ptr);

    ptr = (char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Read: %s\n", ptr);

    shmdt(ptr);

    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed !\n");

    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 30.c -o 30
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./30
Wrote: Hello Swarnendu
Read: Hello Swarnendu
Shared memory removed !
*/