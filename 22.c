/*
============================================================================
Name : 22.c
Author : Swarnendu Sekhar Das
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
              system call with FIFO.

Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/select.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fldes = open("ssdfifo1", O_RDONLY | O_NONBLOCK);
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fldes, &readfds);
    struct timeval tv = {10, 0};
    int ret = select(fldes + 1, &readfds, NULL, NULL, &tv);
    if (ret > 0) {
        char buf[20];
        read(fldes, buf, sizeof(buf));
        printf("Received: %s\n", buf);
    } else if (ret == 0) {
        printf("Timeout after 10 seconds\n");
    } else {
        perror("select");
    }
    close(fldes);
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./22
Hello FIFO
Timeout after 10 seconds
*/