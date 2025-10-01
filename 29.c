/*
============================================================================
Name : 29.c
Author : Swarnendu Sekhar Das
Description : Write a program to remove the message queue.

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0);

    int a = msgctl(msqid, IPC_RMID, NULL);
    if(a != -1){
      printf("Deletion Successful");
    }
    
    return (0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 29.c -o 29
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./29
Deletion Successful
*/