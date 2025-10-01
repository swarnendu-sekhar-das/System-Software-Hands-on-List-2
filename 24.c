/*
============================================================================
Name : 24.c
Author : Swarnendu Sekhar Das
Description : Write a program to create a message queue and print the key and message queue id.

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main() {
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        return 1;
    }
    printf("Key: %d, Message Queue ID: %d\n", key, msqid);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 24.c -o 24
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./24
Key: 1627849256, Message Queue ID: 0
*/