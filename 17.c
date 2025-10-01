/*
============================================================================
Name : 17.c
Author : Swarnendu Sekhar Das
Description : Write a program to execute ls -l | wc.
                a. use dup
                b. use dup2
                c. use fcntl

Date: 25th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd[2];
	pipe(fd);

	int choice = 0;
	printf("1.\t Using dup\n2.\t Using dup2\n3.\t Using fcntl\n\t Enter choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		
		if (!fork())
		{
			int c_value = 100;
			close(fd[0]);
			close(1);
			dup(fd[1]);
			execl("/bin/ls", "/bin/ls", "-l", NULL);
		}
		else
		{
			int p_value;
			close(0);
			close(fd[1]);
			dup(fd[0]);
			execl("/bin/wc", "/bin/wc", NULL);
		}
		break;
	case 2:
		
		if (!fork())
		{
			int c_value = 101;
			close(fd[0]);
			close(1);
			dup2(fd[1], 1);
			execl("/bin/ls", "/bin/ls", "-l", NULL);
		}
		else
		{
			int p_value;
			close(0);
			close(fd[1]);
			dup2(fd[0], 0);
			execl("/bin/wc", "/bin/wc", NULL);
		}
		break;
	case 3:
		
		if (!fork())
		{
			int c_value = 101;
			close(fd[0]);
			close(1);
			fcntl(fd[1], F_DUPFD, 1);
			execl("/bin/ls", "/bin/ls", "-l", NULL);
		}
		else
		{
			int p_value;
			close(0);
			close(fd[1]);
			fcntl(fd[0], F_DUPFD, 0);
			execl("/bin/wc", "/bin/wc", NULL);
		}
		break;
	default:
		break;
	}

	return (0);
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 17.c -o 17
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./17
1.	 Using dup
2.	 Using dup2
3.	 Using fcntl
	 Enter choice: 1
     44     389    3355
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./17
1.	 Using dup
2.	 Using dup2
3.	 Using fcntl
	 Enter choice: 2
     44     389    3355
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./17
1.	 Using dup
2.	 Using dup2
3.	 Using fcntl
	 Enter choice: 3
     44     389    3355
*/