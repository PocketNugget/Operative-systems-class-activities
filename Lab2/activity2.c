#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void write_float_array(const char* filename, float* array, size_t size) {
    // Opens the file
    int fd = open(filename, 2);

    if (fd == -1) {
        perror("Error opening your file");
        return;
    }

    // Writes the array on the txt 
  // It uses the bytes written as a way to see if it was succesfully written
    ssize_t bytes_written = write(fd, array, size * sizeof(float));

    if (bytes_written == -1) {
        perror("Error writing your file");
    } else {
        printf("%zd bytes have been written on the file. \n", bytes_written);
    }

    // Closes the file
    close(fd);
}

int main() {
    // Test case, premade array elements on datos.txt
    float float_array[] = {1.5, 2.7, 3.14, 4.0, 5.2};
    size_t array_size = sizeof(float_array) / sizeof(float);

    // Calls the function to write the array on the txt
    write_float_array("datos.txt", float_array, array_size);

    return 0;
}

