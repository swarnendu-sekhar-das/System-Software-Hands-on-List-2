/*
============================================================================
Name : 34a.c
Author : Swarnendu Sekhar Das
Description : Write a program to create a concurrent server.
                a. use fork

Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
        printf("Received: %s\n", buffer);
        write(client_socket, buffer, bytes_read);  
        memset(buffer, 0, BUFFER_SIZE);
    }
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    listen(server_fd, 3);

    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

        if (fork() == 0) {
            close(server_fd); 
            handle_client(client_socket);
            exit(0);
        } else {
            close(client_socket); 
        }
    }

    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 34a.c -o 34a
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./34a
Server listening on port 8080
Received: Hello from client
*/