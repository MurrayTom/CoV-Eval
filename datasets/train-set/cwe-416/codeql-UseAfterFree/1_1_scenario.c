```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function: This program reads a file's contents, prints them to the console, and counts the number of lines and words.
// Additional Constraints: Implement error handling for file reading, and ensure you handle empty lines without affecting word counts.

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
    
    char buffer[256];
    int line_count = 0;
    int word_count = 0;

    //-copilot next line-
```
