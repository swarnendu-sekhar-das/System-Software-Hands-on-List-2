/*
============================================================================
Name : 26.c
Author : Swarnendu Sekhar Das
Description : Write a program to send messages to the message queue. Check $ipcs -q

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct msg
{
    long mtype;
    char mtext[80];
};

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
  
    struct msg msg;
    msg.mtype = 10;
    char text[80];
    printf("Enter message:\n");
    scanf("%[^\n]s", text);

    strcpy(msg.mtext, text);
    
    if(msgsnd(msqid, (struct msgbuf *)&msg, 80, 0) == -1){
      printf("Message sending failed !");
    }
    else printf("Message sent successfully");

    return (0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 26.c -o 26
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./26
Enter message:
Hi how are you ?
Message sent successfully
*/