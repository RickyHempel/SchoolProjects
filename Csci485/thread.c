/******************************************************************************
 * FILE: thread.c
 * DESCRIPTION:
 *   A threads program.  Demonstrates thread creation and
 *   termination and blocking.
 * AUTHOR: Ricky Hempel
 * LAST REVISED: 03/2/18
   Without the Mutex, the threads kept accessing the balance variable
  simultaneously before the previous thread was finished changing it,
  resulting in the second thread grabbing the balance variable while
  it still has a value of 0. Thus, they are both adding 10 to 0. With the mutex
  the threads are adding 10 to 10 which is 20. 
 
 ******************************************************************************/
//libraries to include
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 2 //number of threads

void *UpdateBalance(void *);//prototype
pthread_mutex_t mutex;//mutex for blocking
int balance=0; //balance to update

int main()
{
  //array of threads
  pthread_t threads[NUM_THREADS];

  int status;
  long i;

  //create thread
  for(i=0;i<NUM_THREADS;i++){
    printf("In main: creating thread %ld\n", i);
    status = pthread_create(&threads[i], NULL, UpdateBalance, (void *)i);
    //print error
    if (status){
      printf("ERROR; return code from pthread_create() is %d\n", status);
      exit(-1);
    }
  }

  /* kill thread*/
  pthread_exit(NULL);
  return 0;
}

void *UpdateBalance(void *tid){
  //locks crit region for thread
  pthread_mutex_lock(&mutex);
  //update and print balance
  int readbalance=balance;
  readbalance +=10;
  usleep(1);//sleep threads
  balance=readbalance;
  printf("The balance is %d\n",balance);
  //unlocks mutex
  pthread_mutex_unlock(&mutex);
  //kills threads
  pthread_exit(NULL);
}
