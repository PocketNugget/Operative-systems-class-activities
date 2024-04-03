#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_m, pid_a, pid_b, pid_c, pid_d;
    int status_a, status_b, status_c, status_d;

    pid_m = getpid();  // Get parent PID
    printf("Parent M (PID: %d)\n", pid_m);

    pid_a = fork();

    if (pid_a == 0) {
        pid_a = getpid();
        printf("Child A (PID: %d), Parent M (PID: %d)\n", pid_a, pid_m);

        pid_d = fork();

        if (pid_d == 0) {
            pid_d = getpid();
            printf("Child D (PID: %d), Parent A (PID: %d)\n", pid_d, pid_a);
            execl("/bin/ls", "ls", NULL);

            exit(1);
        } else if (pid_d < 0) {
            perror("Failed to fork");
            exit(1);
        } else {
            waitpid(pid_d, &status_d, 0);


            execl("/bin/rm", "rm", "-r", "new_folder", NULL);

            exit(1);
        }

        return 1;
    } else if (pid_a < 0) {
        perror("Failed to fork");
        exit(1);
    } else {
        waitpid(pid_a, &status_a, 0);


        pid_c = fork();
        if (pid_c == 0) {
            pid_c = getpid();
            printf("Child C (PID: %d), Parent M (PID: %d)\n", pid_c, pid_m);
            execl("/bin/ls", "ls", NULL);

            exit(1);
        } else if (pid_c < 0) {
            perror("Failed to fork");
            exit(1);
        } else {
            waitpid(pid_c, &status_c, 0);


            pid_b = fork();
            if (pid_b == 0) {
                pid_b = getpid();
                printf("Child B (PID: %d), Parent M (PID: %d)\n", pid_b, pid_m);
                execl("/bin/mkdir", "mkdir", "new_folder", NULL);
    

                exit(1);
            } else if (pid_b < 0) {
                perror("Failed to fork");
                exit(1);
            } else {
                waitpid(pid_b, &status_b, 0);

                
                printf("Soy M y mi PID es: %d\n", getpid());
                execl("/bin/ls", "ls", NULL);

                exit(1);
            }
        }
    }

    return 0;
}

