#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void check_error(int fd, int n, int m) {
    if (fd < 0 || n < 0 || m < 0) {
        perror("Error");
    if (errno == EAGAIN) {
        printf("Error: Resource not available.\n");
        exit(1);
    } else if (errno == EACCES) {
        printf("Error: Permission denied.\n");
        exit(1);
    } else if (errno == EBADF) {
        printf("Error: File descriptor not valid.\n");
        exit(1);
    } else {
        printf("Unknown error.\n");
        exit(1);
    }
  }
}

int main() {
    // Test case
    int fd = open("archivo.txt", 1);
    int n = -1;
    int m = 5;

    check_error(fd, n, m);

    // Closes the file descriptor if it is open
    if (fd >= 0) {
        close(fd);
    }

    return 0;
}

