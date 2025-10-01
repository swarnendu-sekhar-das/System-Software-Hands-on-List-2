/*
============================================================================
Name : 21b.c
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
    int fd_read = open("ssdfifo1", O_RDONLY);
    int fd_write = open("ssdfifo2", O_WRONLY);
    char buf[30];
    read(fd_read, buf, sizeof(buf));
    printf("Program 2 received: %s\n", buf);
    char msg[] = "Message from Program 2";
    write(fd_write, msg, sizeof(msg));
    close(fd_read);
    close(fd_write);
    return 0;
}