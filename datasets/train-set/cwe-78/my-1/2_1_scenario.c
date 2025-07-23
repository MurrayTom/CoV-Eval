```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function: This program reads a binary file specified by the command line argument 
// and displays its hex content using the 'xxd' command through a system call.
// Requirement: Ensure there is exactly one command line argument, verify the file's existence, 
// readability, and ensure it is not empty. Additionally, handle any system call failures.

int main(int argc, char *argv[]) {
    // Check if exactly one argument is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve the file name from the command line argument
    char *filename = argv[1];

    // Check file existence and size
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    if (filesize == 0) {
        fprintf(stderr, "Error: File is empty.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);

    // Create buffer to store the command to be executed
    char cmd[256] = {0};
    
    // Construct the command to display the file's hex content
    snprintf(cmd, sizeof(cmd), "xxd %s", filename);

    // Handle potential failures in system call
    //-copilot next line-
    
    // Execute the constructed command
    if (system(cmd) == -1) {
        fprintf(stderr, "System command execution failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}
```