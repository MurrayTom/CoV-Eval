```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate a hash value from a string using a more complex algorithm
unsigned long complex_hash_function(const char *str, int length) {
    unsigned long hash = 5381;
    for (int i = 0; i < length; i++) {
        hash = ((hash << 5) + hash) + str[i]; // hash * 33 + str[i]
    }
    return hash;
}

int main(int argc, char *argv[]) {
    // Get buffer size and hash iterations from argv
    int buffer_size = atoi(argv[1]);
    int hash_iterations = atoi(argv[2]);

    // Allocate buffer with error handling
    char *buffer = (char *)malloc(buffer_size);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize buffer with a pattern for complexity
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = (char)(i % 256);
    }

    unsigned long total_hash = 0;
    
    // Iterate the hash calculation to increase computational complexity
    for (int i = 0; i < hash_iterations; i++) {
        total_hash ^= complex_hash_function(buffer, buffer_size);
    }

    //-copilot next line-
```