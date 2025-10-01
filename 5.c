/*
============================================================================
Name : 5.c
Author : Swarnendu Sekhar Das
Description : Write a program to print the system limitation of
                a. maximum length of the arguments to the exec family of functions.
                b. maximum number of simultaneous process per user id.
                c. number of clock ticks (jiffy) per second.
                d. maximum number of open files
                e. size of a page
                f. total number of pages in the physical memory
                g. number of currently available pages in the physical memory.
Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>

int main() {
    
    long arg = sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions: %ld\n", arg);
    
    long processes = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user id: %ld\n", processes);

    long clock_ticks = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks per second: %ld\n", clock_ticks);

    long open_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", open_files);

    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in physical memory: %ld\n", total_pages);

    long available_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages in physical memory: %ld\n", available_pages);

    return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 5.c -o 5
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./5
Maximum length of the arguments to the exec family of functions: 2097152
Maximum number of simultaneous processes per user id: 62330
Number of clock ticks per second: 100
Maximum number of open files: 1024
Size of a page: 4096 bytes
Total number of pages in physical memory: 4032683
Number of currently available pages in physical memory: 2207585
*/