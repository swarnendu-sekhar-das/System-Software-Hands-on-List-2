/*
============================================================================
Name : 14.c
Author : Swarnendu Sekhar Das
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
              the monitor.

Date: 25th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){

	int fldes[2];
	
	pipe(fldes);
	printf("pipe created with file descriptor 1 : %d, & file descriptor 2 : %d\n", fldes[0], fldes[1]);

	char arr[30];

	write(fldes[1], "Swarnendu Sekhar Das IIITB", sizeof("Swarnendu Sekhar Das IIITB"));
	read(fldes[0], arr, sizeof(arr) - 1);
    arr[sizeof(arr) - 1] = '\0';
	printf("pipe data is : %s\n", arr);

	return(0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 14.c -o 14
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./14
pipe created with file descriptor 1 : 3, & file descriptor 2 : 4
pipe data is : Swarnendu Sekhar Das IIITB
*/