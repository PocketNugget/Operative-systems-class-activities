#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void sig_handler(int signum) {
  printf("\nAlarm received\n");
  exit(1);
}

int main() {
  pid_t pid_A, pid_B, pid_C;
  int status;

  pid_A = getpid();

  pid_B = fork();
  if (pid_B == 0){
    pid_C = fork();
    if (pid_C == 0){
      while(1){
        printf("Waiting for signal\n");
      }
      pause();
      kill(pid_B,SIGCHLD);
      exit(0);
    }
    else if(pid_C>0){
      sleep(1);
      kill(pid_C,SIGKILL);
      pause();
      kill(pid_A,SIGCHLD);
      exit(0);
    }
  }
  else if(pid_B>0){
    signal(SIGALRM, sig_handler);
    alarm(5);
    pause();
    return 0;
  }

}


