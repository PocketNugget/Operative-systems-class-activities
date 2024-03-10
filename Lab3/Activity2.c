
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_r, pid_t, pid_w, pid_v, pid_s, pid_l, pid_p;

    pid_r = getpid();  //Get father PID
    printf("Father R (PID: %d)\n", pid_r);

    pid_t = fork();

    if (pid_t == 0) {
        pid_t = getpid();
        printf("Child T (PID: %d), Parent R (PID: %d)\n", pid_t, pid_r);

        pid_v = fork();
        if (pid_v == 0) {
            pid_v = getpid();
            printf("Grandchild V (PID: %d), Parent T (PID: %d)\n", pid_v, pid_t);
            exit(0);
        }
    } else if (pid_t > 0) {
      
        pid_w = fork();

        if (pid_w == 0) {
            
            pid_w = getpid();
            printf("Child W (PID: %d), Parent R (PID: %d)\n", pid_w, pid_r);

            pid_s = fork();
            if (pid_s == 0) {
                
                pid_s = getpid();
                printf("Grandchild S (PID: %d), Parent W (PID: %d)\n", pid_s, pid_w);
                exit(0);
            } else if (pid_s > 0) {
               
                pid_l = fork();
                if (pid_l == 0) {
                    
                    pid_l = getpid();
                    printf("Grandchild L (PID: %d), Parent W (PID: %d)\n", pid_l, pid_w);

                    pid_p = fork();
                    if (pid_p == 0) {
                       
                        pid_p = getpid();
                        printf("Great-grandchild P (PID: %d), Parent L (PID: %d)\n", pid_p, pid_l);
                        exit(0);
                    } 
                }
            } 
        }
    }

    return 0;
}
