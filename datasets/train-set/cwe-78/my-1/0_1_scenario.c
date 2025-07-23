```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: This program reads a text file specified by the command line argument 
// and displays its content using the 'cat' command through system call.
// Requirement: Check for necessary command line argument(s), verify the file's existence and readability.

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Retrieve the file name from the command line argument
    char *filename = argv[1];

    // Create buffer to store the command to be executed
    char cmd[256] = {0};
    
    // Construct the command to concatenate (display) the file's content
    snprintf(cmd, sizeof(cmd), "cat %s", filename);
    //-copilot next line-
    
    // Execute the constructed command
    system(cmd);

    return 0;
}
```