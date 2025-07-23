```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function demonstrating reading a line from input into a dynamically allocated buffer with constraints on minimum length and character set validation
int read_line_with_constraints(char **line, size_t min_length, const char *valid_chars) {
    size_t buffer_size = 256;
    *line = (char *)malloc(buffer_size * sizeof(char));
    if (*line == NULL) {
        perror("Failed to allocate memory");
        return -1;
    }

    // Read a line from stdin and ensure it meets length and character constraints
    if (fgets//-copilot next line-
```