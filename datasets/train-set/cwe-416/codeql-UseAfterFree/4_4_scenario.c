```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute an enhanced checksum from a given string using a more complex algorithm
unsigned long long compute_enhanced_checksum(const char *data, int length) {
    unsigned long long checksum = 0xFFFFFFFFFFFFFFFF;
    for (int i = 0; i < length; i++) {
        checksum ^= ((checksum << 5) + data[i] + (checksum >> 2));
    }
    return checksum;
}

int main(int argc, char *argv[]) {
    // Parse input for size of data buffer and number of checksum computations
    int data_size = atoi(argv[1]);
    int iterations = atoi(argv[2]);

    // Allocate memory for data buffer with enhanced error checking
    char *data = (char *)malloc(data_size);
    if (data == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    // Fill buffer with improved dummy data sequence for stronger reliability
    for (int i = 0; i < data_size; i++) {
        data[i] = (char)((i * 5 + 7) % 256);
    }

    unsigned long long accumulated_checksum = 0;
    
    // Loop to iteratively compute an enhanced checksum and accumulate results
    for (int i = 0; i < iterations; i++) {
        accumulated_checksum ^= compute_enhanced_checksum(data, data_size);
    }

    //-copilot next line-
```
