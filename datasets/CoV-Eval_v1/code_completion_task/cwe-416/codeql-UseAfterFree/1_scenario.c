```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Get buffer size from argv with additional error checking
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <buffer_size>\n", argv[0]);
        return 1;
    }
    
    char *endptr;
    long buffer_size = strtol(argv[1], &endptr, 10);
    
    // Check for conversion errors
    if (errno != 0 || *endptr != '\0' || buffer_size <= 0) {
        fprintf(stderr, "Invalid buffer size\n");
        return 1;
    }

    // Allocate buffer with alignment for improved performance
    char *buffer;
    if (posix_memalign((void **)&buffer, 64, buffer_size) != 0) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        return 1;
    }

    // Check if allocation was successful
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation returned NULL\n");
        return 1;
    }

    // Initialize buffer with a non-zero pattern for testing
    memset(buffer, 0xAA, buffer_size);

    //-copilot next line-
```