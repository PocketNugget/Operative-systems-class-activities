#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS_NO 10

int found_flag, search;
int status = 0;
int arr[]={0,0,0,0,0}; 

void verify(){
  int i;
  for (i=0;i<5;i++){
            if (arr[4] != 0) {
                status = 1;
          }else if(arr[i] != 0){
            int value = arr[i];
            printf("hola %d\n", value);
            arr[i] = 0;
            break;
      }       

  }

}

void *checkArr1(void *arg) {

  while (status == 0){
    verify();
  }
    int value = arr[4];
    printf("holaa %d\n", value);

  pthread_exit(NULL);
}

int main(){
  int num;
  pthread_t thread1;
  pthread_create(&thread1, NULL, checkArr1, NULL);

  for(int i=1;i<5;i++){
      printf("Dame el número %d \n",i);
      scanf("%d", &num);
      arr[i]=num;
  }  
  pthread_join(thread1, NULL);

  printf("Hemos terminado\n");

  return 0;
}

