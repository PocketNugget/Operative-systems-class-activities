#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_a, pid_b, pid_c, pid_e;
    int status_b, status_c, status_e;

    pid_a = getpid();  // Get parent PID
    printf("Parent A (PID: %d)\n", pid_a);

    pid_b = fork();

    if (pid_b == 0) {
        pid_b = getpid();
        sleep(3);
        printf("Child B (PID: %d), Parent A (PID: %d)\n", pid_b, pid_a);
        return 1;
    } else if (pid_b < 0) {
        perror("Failed to fork");
        exit(1);
    } else {
        pid_c = fork();
        if (pid_c == 0) {
            pid_c = getpid();
            sleep(1);
            printf("Child C (PID: %d), Parent A (PID: %d)\n", pid_c, pid_a);
            return 2;
        } else if (pid_c < 0) {
            perror("Failed to fork");
            exit(1);
        } else {
            pid_e = fork();
            if (pid_e == 0) {
                pid_e = getpid();
                printf("Child E (PID: %d), Parent A (PID: %d)\n", pid_e, pid_a);
                return 3; // Exit the child process
            } else if (pid_e < 0) {
                perror("Failed to fork");
                exit(1);
            } else {
                // This part of the code runs in the parent process (A)
                // Wait for each child process to finish and print their return values
                waitpid(pid_b, &status_b, 0);
                printf("Child B returned: %d\n", WEXITSTATUS(status_b));

                waitpid(pid_c, &status_c, 0);
                printf("Child C returned: %d\n", WEXITSTATUS(status_c));

                waitpid(pid_e, &status_e, 0);
                printf("Child E returned: %d\n", WEXITSTATUS(status_e));
                
                printf("Todos mis hijos han terminado sus procesos\n");
            }
        }
    }

    return 0;
}

