#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void write_float_to_file(const char* filename, float value, int counter) {
    // Opening the file in write mode
    int fd = open(filename, 2);

    if (fd == -1) {
        perror("Error: Cannot open the file");
        return;
    }

    // Again using the bytes written to be sure it works
    int bytes_written = write(fd, &value, sizeof(float));

    if (bytes_written == -1) {
        perror("Error: cannot write the file");
    } else {
        printf("The %d has been written with a value of %f.\n", counter, value);
    }

    // Closes the file
    close(fd);
}

int main() {
    // Test case, array declaration and ammount of values
    float values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int num_values = sizeof(values) / sizeof(float);
  // For loop used to write / print the elements that are written on the array
    for (int i = 0; i < num_values; ++i) {
        write_float_to_file("datos2.txt", values[i], i);
    }

    return 0;
}


