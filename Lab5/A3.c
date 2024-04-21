#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void sig_handler(int signum) {
  printf("Alarm received\n"); 
}

void sig_handlerC(int signum) {
  printf("I received the SIGUSR2 signal, I am %d, my father is %d\n", getpid(), getppid());
}

void sig_handlerA(int signum) {
  printf("I received the SIGUSR1 signal, I am %d, my father is %d\n", getpid(), getppid());
}

int main() {
  pid_t pid_A, pid_C;
  int status;

  pid_A = fork();

  if (pid_A == 0) {
    // Child process A
    pid_C = fork();
 
    if (pid_C == 0) {
      // Child process C
      signal(SIGUSR2, sig_handlerC);
      pause();       exit(0);
    } else {
      signal(SIGUSR1, sig_handlerA);
      pause();  
      kill(pid_C, SIGUSR2);  
      exit(0);
    }
  } else {
    signal(SIGALRM, sig_handler);
    alarm(3);  
    sleep(3);  
    kill(pid_A, SIGUSR1); 
    waitpid(pid_C, &status, 0);
    waitpid(pid_A, &status, 0);
  }

  return 0;
}

