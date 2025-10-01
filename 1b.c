/*
============================================================================
Name : 1b.c
Author : Swarnendu Sekhar Das
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
              b. ITIMER_VIRTUAL

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_VIRTUAL\n");
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, handler);

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1);
    
    return 0;
}

/*
Output:

swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 1b.c -o 1b
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./1b
ITIMER_VIRTUAL
ITIMER_VIRTUAL
ITIMER_VIRTUAL
ITIMER_VIRTUAL
ITIMER_VIRTUAL

*/