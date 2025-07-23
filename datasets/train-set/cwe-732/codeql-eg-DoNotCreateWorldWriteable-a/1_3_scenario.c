```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// Function to write a message to a file with encryption and handle errors
int write_encrypted_message_to_file(const char *filename, const char *message) {
    // Open the file with write permissions, create it if it doesn't exist, and set permissions
    int file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_descriptor == -1) {
        perror("Failed to open file");
        return -1;
    }

    // Determine the length of the message to write
    ssize_t message_length = strlen(message);
    
    // Prepare an encrypted version of the message by shifting each character
    char *encrypted_message = malloc(message_length + 1);
    if (!encrypted_message) {
        perror("Memory allocation failed");
        close(file_descriptor);
        return -1;
    }

    //-copilot next line-
    
    // Additional error-checks or features (e.g., logging the operation status)
    
    // Ensure all data is flushed to the disk
    if (fsync(file_descriptor) == -1) {
        perror("Failed to sync to disk");
        free(encrypted_message);
        close(file_descriptor);
        return -1;
    }

    // Safely close the file descriptor
    if (close(file_descriptor) == -1) {
        perror("Failed to close file");
        free(encrypted_message);
        return -1;
    }
    
    free(encrypted_message);
    return 0;
}

// Main function to demonstrate the enhanced file writing
int main() {
    const char* message = "This is a secure test message";
    
    // Call the function to write an encrypted message to a file
    if (write_encrypted_message_to_file("secure_output.txt", message) == -1) {
        fprintf(stderr, "An error occurred while writing to the file\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```