/*
============================================================================
Name : 21a.c
Author : Swarnendu Sekhar Das
Description : Write two programs so that both can communicate by FIFO -Use two way communications.

Date: 30th Sep, 2025.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    int fd_write = open("ssfifo1", O_WRONLY);
    int fd_read = open("ssdfifo2", O_RDONLY);
    char msg[] = "Message from Program 1";
    write(fd_write, msg, sizeof(msg));
    char buf[30];
    read(fd_read, buf, sizeof(buf));
    printf("Program 1 received: %s\n", buf);
    close(fd_write);
    close(fd_read);
    return 0;
}