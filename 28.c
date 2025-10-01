/*
============================================================================
Name : 28.c
Author : Swarnendu Sekhar Das
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main() {
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0666);
    struct msqid_ds ds;
    msgctl(msqid, IPC_STAT, &ds);
    ds.msg_perm.mode = 0600;
    if (msgctl(msqid, IPC_SET, &ds) == -1) {
        perror("msgctl IPC_SET");
    }
    printf("Permissions changed to 0600.\n");
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 28.c -o 28
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./28
Permissions changed to 0600.
*/