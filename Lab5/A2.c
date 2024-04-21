#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler(int signum) { printf("Se esperan 3 segundos\n"); }

int main() {
  signal(SIGALRM, sig_handler); // Register signal handler

  alarm(3);
  for (int i = 1;; i++) {
    printf("");
    sleep(1);
  }
  return 0;
}
