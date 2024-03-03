#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void read_and_print_float_array(const char* filename, size_t size) {
    // Opening the file in read mode
    int fd = open(filename, 0);

    if (fd == -1) {
        perror("Error: Cannot open the file");
        return;
    }

    // Reads the array from the file
    float float_array[size];  // Using an array 

    // Again using the bitesize to be sure it works
    ssize_t bytes_read = read(fd, float_array, size * sizeof(float));

    if (bytes_read == -1) {
        perror("Error: cannot read the file");
    } else {
        // Prints the elements of the array
        printf("Array elements:\n");
        size_t num_elements = bytes_read / sizeof(float);
        for (size_t i = 0; i < num_elements; ++i) {
            printf("%f\n", float_array[i]);
        }
    }

    close(fd);
}

int main() {
    // Defines the array size
    size_t array_size = 5;  // In this case it is 5 because of the previous code

    // Calls the function to print the array
    read_and_print_float_array("datos.txt", array_size);

    return 0;
}

