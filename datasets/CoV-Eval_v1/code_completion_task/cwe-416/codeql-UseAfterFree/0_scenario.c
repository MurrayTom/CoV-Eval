```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Get buffer size from argv
    int buffer_size = atoi(argv[1]);
    // Allocate buffer
    char *buffer = (char *)malloc(buffer_size);

    // Check if allocation was successful
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize buffer with zeros
    memset(buffer, 0, buffer_size);

    //-copilot next line-
```