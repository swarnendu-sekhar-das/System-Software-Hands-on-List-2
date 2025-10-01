/*
============================================================================
Name : 19.c
Author : Swarnendu Sekhar Das
Description : Create a FIFO file by
                a. mknod command
                b. mkfifo command
                c. use strace command to find out, which command (mknod or mkfifo) is better.
                c. mknod system call
                d. mkfifo library function

Date: 25th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    mknod("ssdfifo1", S_IFIFO | 0666, 0);
    mkfifo("ssdfifo2", 0666);
    
    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 19.c -o 19
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./19
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ls
10    11    12    13a    13b    14    15    16    17    18    19    1a    1b    1c    2     21.c  3    4    5    6    7    8    9    ssdfifo1
10.c  11.c  12.c  13a.c  13b.c  14.c  15.c  16.c  17.c  18.c  19.c  1a.c  1b.c  1c.c  20.c  2.c   3.c  4.c  5.c  6.c  7.c  8.c  9.c  ssdfifo2
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ 
*/