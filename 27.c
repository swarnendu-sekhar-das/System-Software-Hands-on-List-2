/*
============================================================================
Name : 27.c
Author : Swarnendu Sekhar Das
Description : Write a program to receive messages from the message queue.
              a. with 0 as a flag
              b. with IPC_NOWAIT as a flag

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

struct msg {
    long type;
    char text[80];
};

int main() {
    key_t key = ftok(".", 'a');
    struct msg message;
    int msqid = msgget(key, 0);
   
   int flag, mtype;
    printf("Choose flag:\n1.) 0 (blocking)\n2.) IPC_NOWAIT (non-blocking)\n=> ");
    scanf("%d", &flag);

    printf("Enter message type:\n");
    scanf("%d", &mtype);

    int recv_flag = (flag == 2) ? IPC_NOWAIT : 0;

    if (msgrcv(msqid, &message, sizeof(message.text), mtype, recv_flag) == -1) {
        perror("msgrcv");
    } else {
        printf("Message: %s\n", message.text);
    }

    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 27.c -o 27
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./27
Choose flag:
1.) 0 (blocking)
2.) IPC_NOWAIT (non-blocking)
=> 1
Enter message type:
0
Message: Hi how are you ?

swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./27
Choose flag:
1.) 0 (blocking)
2.) IPC_NOWAIT (non-blocking)
=> 2
Enter message type:
0
msgrcv: No message of desired type
*/