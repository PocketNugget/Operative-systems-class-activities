#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void read_and_print_floats(const char* filename) {
    // Open the file in read mode
    int fd = open(filename, 0);

    if (fd == -1) {
        perror("Error: Cannot open the file");
        return;
    }

    // Read float values from the file
    float value;
    int bytes_read;

    printf("Values read from %s:\n", filename);

    while ((bytes_read = read(fd, &value, sizeof(float))) > 0) {
        // Print the read value
        printf("%f\n", value);
    }

    if (bytes_read == -1) {
        perror("Error: Cannot read the file");
    }

    // Close the file
    close(fd);
}

int main() {
    // Call the function to read and print the values
    read_and_print_floats("datos2.txt");

    return 0;
}

