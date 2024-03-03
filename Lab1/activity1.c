#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void manejarErrores(int valor) {
    if (valor < 0) {
        switch (errno) {
            case EAGAIN:
                printf("Error: Operación bloqueada, intenta nuevamente más tarde\n");
                break;
            case EACCES:
                printf("Error: Permiso denegado\n");
                break;
            case EBADF:
                printf("Error: Descriptor de archivo no válido\n");
                break;
            default:
                perror("Error");
        }
    } else {
        printf("El valor es positivo o cero\n");
    }
}

int main() {
    int fd, n, m;

    printf("Introduce el valor para fd: ");
    scanf("%d", &fd);

    printf("Introduce el valor para n: ");
    scanf("%d", &n);

    printf("Introduce el valor para m: ");
    scanf("%d", &m);

    manejarErrores(fd);
    manejarErrores(n);
    manejarErrores(m);

    return 0;
}

