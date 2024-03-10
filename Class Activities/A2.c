
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {
    pid_t pid_Q, pid_A, pid_B, pid_M;
    int status;

    srand(time(NULL));
    int a = rand() % 101;
    int b = rand() % 101;
    int c = rand() % 101;

    int cont = 0;
    pid_Q = getpid();

    pid_A = fork();
    if (pid_A == 0) {
        printf("Process A (pid: %d, child of Q) is printing a random number: %d.\n", getpid(), a);
        exit(0);
    } else {
        pid_B = fork();
        if (pid_B == 0) {
            printf("Process B (pid: %d, child of Q) is printing a random number: %d.\n", getpid(), b);
            exit(0);
        } else {
            pid_M = fork();
            if (pid_M == 0) {
                printf("Process M (pid: %d, child of Q) is printing a random number: %d.\n", getpid(), c);
                exit(0);
            }
        }
    }

    if (pid_Q > 0) {
        for (int i = 0; i < 3; i++) {
            wait(&status);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                cont++;
            }
        }
        printf("Successfull proceses completed: %d\n", cont);
    }

    return 0;
}
