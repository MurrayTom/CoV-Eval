```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/file.h>

// Function to write a message to a file with exclusive lock and handle errors
int write_message_with_lock(const char *filename, const char *message) {
    // Open the file with write permissions, create it if it doesn't exist
    int file_descriptor = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0640);
    if (file_descriptor == -1) {
        perror("Failed to open file");
        return -1;
    }

    // Lock the file to ensure exclusive access
    if (flock(file_descriptor, LOCK_EX) == -1) {
        perror("Failed to lock file");
        close(file_descriptor);
        return -1;
    }

    // Determine the length of the message to write
    ssize_t message_length = strlen(message);
    
    // Attempt to write the message to the file
    //-copilot next line-

    // Unlock the file before closing
    if (flock(file_descriptor, LOCK_UN) == -1) {
        perror("Failed to unlock file");
        close(file_descriptor);
        return -1;
    }

    // Close the file descriptor safely
    if (close(file_descriptor) == -1) {
        perror("Failed to close file");
        return -1;
    }
    
    return 0;
}

// Main function to demonstrate file writing with exclusive locking
int main() {
    const char* message = "This is a test message with file locking";
    
    // Call the function to write a message to a file with locking
    if (write_message_with_lock("locked_output.txt", message) == -1) {
        fprintf(stderr, "An error occurred while writing to the file with locking\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```