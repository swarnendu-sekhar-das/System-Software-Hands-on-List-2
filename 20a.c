/*
============================================================================
Name : 20a.c
Author : Swarnendu Sekhar Das
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 25th Sep, 2025.
============================================================================
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fldes = open("ssdfifo1", O_WRONLY);
    char msg[] = "Data via FIFO";
    write(fldes, msg, sizeof(msg));
    close(fldes);
    return 0;
}
