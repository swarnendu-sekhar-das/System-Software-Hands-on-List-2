/*
============================================================================
Name : 16.c
Author : Swarnendu Sekhar Das
Description : Write a program to send and receive data from parent to child vice versa. Use two way
              communication.

Date: 25th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd_pc[2];
	int fd_cp[2];
	
	pipe(fd_cp);
	pipe(fd_pc);

	if(!fork()){
		int childval = 1000;
		close(fd_cp[0]);
		write(fd_cp[1], &childval, sizeof(int));

		int c_val;
		close(fd_pc[1]);
		read(fd_pc[0], &c_val, sizeof(int));
		printf("Data from Parent to Child: %d\n", c_val);
	}
	else{
		int parentval;
		close(fd_cp[1]);
		read(fd_cp[0], &parentval, sizeof(int));
		printf("Data from Child to Parent: %d\n", parentval);

		int p_val = 2000;
		close(fd_pc[0]);
		write(fd_pc[1], &p_val, sizeof(int));
	}

	return(0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 16.c -o 16
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./16
Data from Child to Parent: 1000
Data from Parent to Child: 2000
*/