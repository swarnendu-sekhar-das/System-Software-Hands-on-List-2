/*
============================================================================
Name : 25.c
Author : Swarnendu Sekhar Das
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                a. access permission
                b. uid, gid
                c. time of last message sent and received
                d. time of last change in the message queue
                d. size of the queue
                f. number of messages in the queue
                g. maximum number of bytes allowed
                h. pid of the msgsnd and msgrcv

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <time.h>

int main() {
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0666);
    struct msqid_ds ds;
    msgctl(msqid, IPC_STAT, &ds);

    printf("a. Access permission: %o\n", ds.msg_perm.mode);
    printf("b. UID: %d, GID: %d\n", ds.msg_perm.uid, ds.msg_perm.gid);
    printf("c. Time of last message sent: %s", ctime(&ds.msg_stime));
    printf("   Time of last message received: %s", ctime(&ds.msg_rtime));
    printf("d. Time of last change: %s", ctime(&ds.msg_ctime));
    printf("e. Size of the queue (bytes): %lu\n", ds.__msg_cbytes);
    printf("f. Number of messages: %lu\n", ds.msg_qnum);
    printf("g. Maximum bytes allowed: %lu\n", ds.msg_qbytes);
    printf("h. PID of last msgsnd: %d, PID of last msgrcv: %d\n", ds.msg_lspid, ds.msg_lrpid);

    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 25.c -o 25
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./25
a. Access permission: 666
b. UID: 1000, GID: 1000
c. Time of last message sent: Thu Jan  1 05:30:00 1970
   Time of last message received: Thu Jan  1 05:30:00 1970
d. Time of last change: Wed Oct  1 01:11:51 2025
e. Size of the queue (bytes): 0
f. Number of messages: 0
g. Maximum bytes allowed: 16384
h. PID of last msgsnd: 0, PID of last msgrcv: 0
*/