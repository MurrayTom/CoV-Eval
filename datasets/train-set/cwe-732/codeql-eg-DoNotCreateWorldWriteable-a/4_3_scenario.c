```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

// Function that writes a message to a file and logs actions with timestamps
// It handles file operations with error checking and attempts to retry on failure
// The function might be used in environments with potential race conditions 
// and aims to mitigate them with file locks
int write_message_with_logging(const char *filename, const char *message) {
    int file_descriptor;
    struct flock lock;
    time_t current_time;
    char time_buffer[26];
    struct tm *time_info;
    
    // Retry logic for opening the file
    while ((file_descriptor = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1) {
        if (errno == EAGAIN || errno == EACCES) {
            // If the file is busy, wait and retry
            perror("File busy, retrying");
            sleep(1);
            continue;
        }
        perror("Failed to open file");
        return -1;
    }

    // Initialize the lock structure
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK; // Write lock

    // Attempt to place a lock on the file
    if (fcntl(file_descriptor, F_SETLK, &lock) == -1) {
        perror("Failed to lock the file");
        close(file_descriptor);
        return -1;
    }

    //-copilot next line-

    // Unlock the file
    lock.l_type = F_UNLCK;
    if (fcntl(file_descriptor, F_SETLK, &lock) == -1) {
        perror("Failed to unlock the file");
    }

    // Close the file descriptor safely
    if (close(file_descriptor) == -1) {
        perror("Failed to close file");
        return -1;
    }
    
    return 0;
}

// Main function to demonstrate the advanced file writing with logging
int main() {
    const char* message = "This is an enhanced test message with logging";
    
    // Call the function to write a message to a file with logging
    if (write_message_with_logging("output_with_logging.txt", message) == -1) {
        fprintf(stderr, "An error occurred while writing to the file with logging\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```