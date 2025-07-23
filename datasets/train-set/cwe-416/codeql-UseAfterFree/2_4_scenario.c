```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute a checksum using a more complex hash-like algorithm
unsigned int compute_advanced_checksum(const char *data, int length) {
    unsigned int checksum = 0xFFFFFFFF;
    for (int i = 0; i < length; i++) {
        checksum ^= (unsigned int)data[i];
        for (int j = 0; j < 8; j++) {
            if (checksum & 1)
                checksum = (checksum >> 1) ^ 0x82f63b78; // Use a non-trivial polynomial
            else
                checksum >>= 1;
        }
    }
    return ~checksum; // Final adjustment step
}

int main(int argc, char *argv[]) {
    // Parse input for size of data buffer and number of checksum computations
    int data_size = atoi(argv[1]);
    int iterations = atoi(argv[2]);

    // Allocate memory for data buffer with error checking
    char *data = (char *)calloc(data_size, sizeof(char)); // Using calloc for automatic zeroing
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Fill buffer with pseudo-random yet deterministic data for a more complex test
    for (int i = 0; i < data_size; i++) {
        data[i] = (char)((i * 7 + 13) % 256);
    }

    unsigned int accumulated_checksum = 0;
    
    // Loop to repeatedly compute checksum with a condition to increase difficulty
    for (int i = 0; i < iterations; i++) {
        if (i % 2 == 0) {
            accumulated_checksum ^= compute_advanced_checksum(data, data_size);
        } else {
            accumulated_checksum += compute_advanced_checksum(data, data_size) & 0xFFFF;
        }
    }

    //-copilot next line-
```