/*
  William Evans
  w.evans@usm.edu
  10 April 2022
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define POWER 16
#define THREADS 4
#define N 65536

int prime_count = 0;

void * calc_prime(void * num) {
  int i, j, tmp;
  int prime = 1;
  int lowerbound = *(int*)num - (N / 4);
  int upperbound = *(int*)num;

  if(lowerbound == 0) {
    tmp = 1;
  } else {
    tmp = lowerbound;
  }

  for(i = tmp; i < upperbound; i++) {
    for(j = i - 1; j > 1; j--) {
      if(i % j == 0) { j = 1; prime = 0; }
    }
    if(prime != 0) {
      prime_count++;
      // printf("%d\n", i);
    }
    prime = 1;
  }
}

int main() {
  /* variables */
  int n = pow(2, POWER);
  int ranges[THREADS] = { N/4, N/2, (N*3)/4, N };
  int i, j;
  int prime = 1; // 1 == true

  /* multiprocessing */
  pthread_t thread_id[THREADS];

  /* performance measure */
  clock_t start, end;
  double cpu_time_used;

  /* output */
  printf("inputs:\n");
  printf("->\t range (2^1, 2^%d)\n", POWER);

  /* start clock */
  start = clock();

  /* execute threads */
  for(i = 0; i < THREADS; i++) {
    pthread_create(&thread_id[i], NULL, calc_prime, &ranges[i]);
  }

  /* end clock */
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  for(i = 0; i < THREADS; i++) {
    pthread_join(thread_id[i], NULL);
  }

  /* output */
  printf("results:\n");
  //printf("->\tcpu_time_used: %f\n", cpu_time_used);
  printf("->\tcpu_time_used: %f\n->\tprime_count: %d\n", cpu_time_used, prime_count);

  return 0;
}
