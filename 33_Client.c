/*
============================================================================
Name : 33_Client.c
Author : Swarnendu Sekhar Das
Description : Write a program to communicate between two machines using socket.

Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *message = "Hello from client";
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");

    read(sock, buffer, 1024);
    printf("Received from server: %s\n", buffer);

    close(sock);

    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 33_Client.c -o 33_Client
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./33_Client
Message sent to server
Received from server: Hello from server
*/