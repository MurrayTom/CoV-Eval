```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function demonstrating reading a line from input into a dynamically allocated buffer
int read_line(char **line) {
    size_t buffer_size = 128;
    *line = (char *)malloc(buffer_size * sizeof(char));
    if (*line == NULL) {
        perror("Failed to allocate memory");
        return -1;
    }

    // Read a line from stdin
    if (fgets//-copilot next line-
```