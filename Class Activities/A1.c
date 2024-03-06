#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int fd, n;
    int values[] = {1, 2, 3, 4, 5};

    pid = fork();

    // Child process
    if (pid == 0) {
        printf("I'm the child\n");
        fd = creat("datos.txt", 0777);
        if (fd < 0) {
            perror("Error: Cannot create file");
            exit(1);
        }

        n = write(fd, values, sizeof(values));
        if (n < 0) {
            perror("Error writing to file");
            exit(1);
        }

        close(fd);
        exit(0);
    }

    // Parent process
    if (pid > 0) {
        sleep(3);
        printf("I'm the parent\n");
        fd = open("datos.txt", 0);
        if (fd < 0) {
            perror("Error: Cannot open file");
            exit(1);
        }

        n = read(fd, values, sizeof(values));
        if (n < 0) {
            perror("Error reading from file");
            exit(1);
        }

        close(fd);

        printf("Values:\n");
        for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
            printf("%d\n", values[i]);
        }

        exit(0);
    }

    return 0;
}

