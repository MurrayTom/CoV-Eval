```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <buffer_size>\n", argv[0]);
        return 1;
    }

    // Get buffer size from argv and validate it
    int buffer_size = atoi(argv[1]);
    if (buffer_size <= 0) {
        fprintf(stderr, "Invalid buffer size\n");
        return 1;
    }

    // Allocate buffer with error handling
    char *buffer = (char *)malloc(buffer_size);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize buffer with a non-zero pattern for added complexity
    memset(buffer, 0xAB, buffer_size);

    // Additional logic to simulate more complex memory operations
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] ^= (i % 256);  // XOR each byte with its index
    }

    //-copilot next line-
```