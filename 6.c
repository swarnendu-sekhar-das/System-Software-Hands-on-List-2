/*
============================================================================
Name : 6.c
Author : Swarnendu Sekhar Das
Description : Write a simple program to create three threads.

Date: 23rd Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <pthread.h>

void* foo(void* p){

    int threadID = *((int*)p);
    printf("Thread %d is being executed !\n", threadID);
    return NULL;
}

int main(void){
  pthread_t id[3];

  int id1 = 1;
  int id2 = 2;
  int id3 = 3;
  
  pthread_create(&id[0], NULL, foo, &id1);
  pthread_create(&id[1], NULL, foo, &id2); 
  pthread_create(&id[2], NULL, foo, &id3);
  
  pthread_join(id[0], NULL);
  pthread_join(id[1], NULL);
  pthread_join(id[2], NULL);
  
  return 0;
}

/*
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ gcc 6.c -o 6
swarnendu-sekhar-das@swarnendu-sekhar-das-G5-5500:~/Desktop/SS-Hands on List 2$ ./6
Thread 1 is being executed !
Thread 3 is being executed !
Thread 2 is being executed !
*/