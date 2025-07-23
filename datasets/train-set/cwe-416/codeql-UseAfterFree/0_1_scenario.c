```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: This program reads a file's contents and prints them to the console.
// Requirements: Implement a function to open a file provided as a command-line argument and handle any file opening or reading errors.

int main(int argc, char *argv[]) {
    // Verify that a file path is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
    
    const char *file_path = argv[1];

    // Attempt to open the file
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    //-copilot next line-
```