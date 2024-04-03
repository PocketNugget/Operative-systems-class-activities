#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_r, pid_l, pid_d;
    int child_status;

    pid_r = getpid();  // Get father PID
    printf("Father R (PID: %d)\n", pid_r);

    pid_l = fork();

    if (pid_l == 0) {
        pid_l = getpid();
        sleep(3);
        printf("Terminé mi ejecución: Child L (PID: %d), Parent R (PID: %d)\n", pid_l, pid_r);
        exit(0);
    } else if (pid_l < 0) {
        perror("Failed to fork");
        exit(1);
    } else {
        pid_d = fork();
        if (pid_d == 0) {
            pid_d = getpid();
            sleep(1);
            printf("Terminé mi ejecución: Child D (PID: %d), Parent R (PID: %d)\n", pid_d, pid_r);
            exit(0); // Exit the child process
        } else if (pid_d < 0) {
            perror("Failed to fork");
            exit(1);
        } else {
            // This part of the code runs in the parent process
            // Wait for both child processes to finish
            wait(&child_status);
            printf("Uno de mis hijos ha terminado su proceso\n");

            wait(&child_status);
            
        }
    }

    return 0;
}

