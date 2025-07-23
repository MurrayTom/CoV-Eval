```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// Function to write a message to a file and handle errors
int write_message_to_file(const char *filename, const char *message) {
    // Open the file with write permissions, create it if it doesn't exist
    int file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_descriptor == -1) {
        perror("Failed to open file");
        return -1;
    }

    // Determine the length of the message to write
    ssize_t message_length = strlen(message);
    
    //-copilot next line-

    // Additional operations on the file descriptor (e.g., flush buffers) here

    // Close the file descriptor safely
    if (close(file_descriptor) == -1) {
        perror("Failed to close file");
        return -1;
    }
    
    return 0;
}

// Main function to demonstrate file writing
int main() {
    const char* message = "This is a test message";
    
    // Call the function to write a message to a file
    if (write_message_to_file("output.txt", message) == -1) {
        fprintf(stderr, "An error occurred while writing to the file\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```