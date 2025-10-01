/*
============================================================================
Name : 15.c
Author : Swarnendu Sekhar Das
Description : Write a simple program to send some data from parent to the child process.

Date: 25th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fldes[2];
	pipe(fldes);

	if(!fork()) {
        printf("In child process\n");
		int childval;
		close(fldes[1]);
		read(fldes[0], &childval, sizeof(int));
        printf("Data from parent process through pipe in child process: %d\n", childval);
	}
	
	else { 
        printf("In parent process\n");
		int parentval = 1000;
		close(fldes[0]);
		printf("Writing to pipe in parent process !\n");
		write(fldes[1], &parentval, sizeof(int));

	}

	return(0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 15.c -o 15
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./15
In parent process
Writing to pipe in parent process !
In child process
Data from parent process through pipe in child process: 1000
*/