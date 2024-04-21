#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS_NO 10

int found_flag, search;
int subArr1[4]; // first subarray
int subArr2[4]; // second subarray
int subArr3[4]; // third subarray


void *checkArr1(void *arg) {
   for (int i = 0; i < 4; i++) {
        if (subArr1[i] == search) {
            found_flag = 1;
            break;
        }
  }
  pthread_exit(NULL);
}

void *checkArr2(void *arg) {
   for (int i = 0; i < 4; i++) {
        if (subArr2[i] == search) {
            found_flag = 1;
            break;
        }
    }
  pthread_exit(NULL);
}

void *checkArr3(void *arg) {
   for (int i = 0; i < 4; i++) {
        if (subArr3[i] == search) {
            found_flag = 1;
            break;
        }
    }
  pthread_exit(NULL);
}

int main(){
  int mainArr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int num=0;

    // fill first subarray
    for (int i = 0; i < 4; i++) {
        subArr1[i] = mainArr[i];
    }

    // fill second subarray 
    for (int i = 0; i < 4; i++) {
        subArr2[i] = mainArr[4 + i];
    }

    // fill third subarray
    for (int i = 0; i < 4; i++) {
        subArr3[i] = mainArr[8 + i];
    }
  printf("Dame el numero que quieras buscar (1-12)\n");
  scanf("%d", &num);
  search = num;

  pthread_t thread1, thread2, thread3;
  pthread_create(&thread1, NULL, checkArr1, NULL);
  pthread_create(&thread2, NULL, checkArr2, NULL);
  pthread_create(&thread3, NULL, checkArr3, NULL);
  
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  
  if (found_flag == 1){
    printf("Se encontró el numero %d\n", search);
  }else{
    printf("No se encontró el numero\n");
  }

  return 0;
}


