/*
============================================================================
Name : 1a.c
Author : Swarnendu Sekhar Das
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
              a. ITIMER_REAL

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_REAL\n");
}

int main(){
    struct itimerval timer;
    
    signal(SIGALRM, handler);
    
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    
    setitimer(ITIMER_REAL, &timer, NULL);

    while(1);

    return 0;
}

/*
Output:

swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./1a
ITIMER_REAL
ITIMER_REAL
ITIMER_REAL
ITIMER_REAL
ITIMER_REAL
ITIMER_REAL
ITIMER_REAL

*/