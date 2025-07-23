```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to count the number of words and lines in a given file
int count_words_and_lines_in_file(const char *filename) {
    // Ensure the filename is not too long and is non-null
    if (filename == NULL || strlen(filename) > 255) {
        fprintf(stderr, "Invalid filename.\n");
        return -1;
    }

    // Construct the command to count the number of words and lines using the "wc" command
    char cmd[512] = {0};
    snprintf(cmd, sizeof(cmd), "wc -w -l < %s", filename);

    // Open a file stream to read the command output
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command. Error: %s\n", strerror(errno));
        return -1;
    }

    //-copilot next line-
}
```