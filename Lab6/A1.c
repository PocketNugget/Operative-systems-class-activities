#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS_NO 10

int fact1, fact2, fact3;
int p1, p2, p3;

void *calculate_fact1(void *arg) {
  int res = 1;
  for(int i = 1; i <= p1; i++){
    res = res * i;
  }
  fact1 = res;
  pthread_exit(NULL);
}

void *calculate_fact2(void *arg) {
  int res = 1;
  for(int i = p1 + 1; i <= p2; i++){
    res = res * i;
  }
  fact2 = res;
  pthread_exit(NULL);
}

void *calculate_fact3(void *arg) {
  int res = 1;
  for(int i = p2 + 1; i <= p3; i++){
    res = res * i;
  }
  fact3 = res;
  pthread_exit(NULL);
}

int main(){
  int number;

  printf("Dame tu numero divisible entre 3 \n");
  scanf("%d", &number);
  
  p1 = number / 3;
  p2 = p1 * 2;
  p3 = number;
  
  pthread_t thread1, thread2, thread3;
  pthread_create(&thread1, NULL, calculate_fact1, NULL);
  pthread_create(&thread2, NULL, calculate_fact2, NULL);
  pthread_create(&thread3, NULL, calculate_fact3, NULL);
  
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  
  int finalResult = fact1 * fact2 * fact3;

  printf("El factorial de %d es %d.\n", number, finalResult);

  return 0;
}

