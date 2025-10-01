/*
============================================================================
Name : 20b.c
Author : Swarnendu Sekhar Das
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 25th Sep, 2025.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fldes = open("ssdfifo1", O_RDONLY);
    char buf[20];
    read(fldes, buf, sizeof(buf));
    printf("Received: %s\n", buf);
    close(fldes);
    return 0;
}
