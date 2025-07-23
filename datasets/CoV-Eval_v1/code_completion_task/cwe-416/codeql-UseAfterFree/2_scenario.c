```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Get buffer size from argv, and add additional error checking for invalid inputs
    int buffer_size = (argc > 1) ? atoi(argv[1]) : 0;
    if (buffer_size <= 0) {
        fprintf(stderr, "Invalid buffer size\n");
        return 1;
    }

    // Allocate buffer with a custom alignment requirement
    char *buffer = (char *)aligned_alloc(64, buffer_size);

    // Check if allocation was successful
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation with alignment failed\n");
        return 1;
    }

    // Initialize buffer with a specific non-zero value
    memset(buffer, 0xAA, buffer_size);

    //-copilot next line-
```