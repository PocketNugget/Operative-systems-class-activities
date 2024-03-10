#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    creat("Ndat.txt", 0666);
    creat("Mdat.txt", 0666);
    pid_t pid_n, pid_m, p;

    pid_n = fork();

    // Código del hijo N
    if (pid_n == 0) {
        printf("I'm son N\n");
        int fd;
        fd = open("Ndat.txt", 750);
        int tempArray[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        for (int i = 0; i < 10; i++) {
            write(fd, &tempArray[i], sizeof(tempArray[0]));
        }
        close(fd);
        exit(0);
    }

    pid_m = fork();
    if (pid_m == 0) {
        printf("I'm son M\n");
        int fd;
        fd = open("Mdat.txt", 750);
        int tempArray[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        for (int i = 0; i < 10; i++) {
            write(fd, &tempArray[i], sizeof(tempArray[0]));
        }
        close(fd);
        exit(0);
    }

    if (pid_n > 0 && pid_m > 0) {
        printf("I'm the father\n");

        int tempArray[10];
        int tempArray2[10];
        int resultArray[10];
        int fd;
        int fd2;
        fd = open("Ndat.txt", 0);
        fd2 = open("Mdat.txt", 0);
        for (int i = 0; i < 10; i++) {
            read(fd, &tempArray[i], sizeof(tempArray[0]));
            read(fd2, &tempArray2[i], sizeof(tempArray2[0]));
            resultArray[i] = tempArray[i] + tempArray2[i];
        }
        printf("Result Array:");
        for (int i = 0; i < 10; i++) {
            if (i < 9) {
                printf(" %d,", resultArray[i]);
            } else {
                printf(" %d ", resultArray[i]);
            }
        }
        printf("\n");
        close(fd);
        close(fd2);
    }

    return 0;
}

