/*
============================================================================
Name : 1c.c
Author : Swarnendu Sekhar Das
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
              c. ITIMER_PROF

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_PROF\n");
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handler);

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1);

    return 0;
}

/*
Output:
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./1c
ITIMER_PROF
ITIMER_PROF
ITIMER_PROF
*/