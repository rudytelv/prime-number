#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define POWER 16
#define N 65536

int main() {
  int i, j, tmp;
  int prime = 1;
  int lowerbound = 0;
  int upperbound = pow(2, POWER);
  int prime_count = 0;

  if(lowerbound == 0) {
    tmp = 1;
  } else {
    tmp = lowerbound;
  }

  /* performance measure */
  clock_t start, end;
  double cpu_time_used;

  /* start clock */
  start = clock();

  /* find prime numbers */
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

  /* end clock */
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  /* output */
  printf("results:\n");
  //printf("->\tcpu_time_used: %f\n", cpu_time_used);
  printf("->\tcpu_time_used: %f\n->\tprime_count: %d\n", cpu_time_used, prime_count);

  return 0;
}
