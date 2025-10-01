/*
============================================================================
Name : 11.c
Author : Swarnendu Sekhar Das
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
              use sigaction system call.

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <bits/sigaction.h>

int main(){
    struct sigaction sa;

    sa.sa_handler = SIG_IGN;
    sigaction(SIGINT,&sa,NULL);
    printf("Ignoring SIGINT for 5 seconds\n");
    sleep(5);
    
    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT,&sa,NULL);
    printf("\nDefault of SIGINT\n");
    
    for(;;){

    };
    
    return(0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 11.c -o 11
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./11
Ignoring SIGINT for 5 seconds

Default of SIGINT
^C
*/