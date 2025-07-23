```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function: This program reads a file's contents and prints them to the console, but with additional logic to count the number of lines, words, and characters in the file.
// Requirements: Implement a function to open a file provided as a command-line argument, handle any file opening or reading errors, and compute line, word, and character counts.

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

    char ch;
    int lines = 0, words = 0, characters = 0;
    int in_word = 0;

    //-copilot next line-
```