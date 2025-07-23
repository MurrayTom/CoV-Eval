```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: Allocate a large block of memory, initialize it with zeros, 
// and perform an additional check to verify zero initialization.
// Also, ensure that the allocated block is aligned with a specified 
// alignment boundary (e.g., 64 bytes).
void initializeAndCheckMemory() {
    // Define a pointer for the memory block
    char* memoryBlock;

    // Define alignment requirement
    const size_t alignment = 64;

    // Allocate aligned memory of size 4096 bytes
    if (posix_memalign((void**)&memoryBlock, alignment, 4096) != 0) {
        fprintf(stderr, "Failed to allocate aligned memory\n");
        return;
    }

    // Initialize the memory block with zeros
    memset(memoryBlock, 0, 4096);

    // Add check to ensure all bytes are initialized to zero
    for (size_t i = 0; i < 4096; i++) {
        if (memoryBlock[i] != 0) {
            fprintf(stderr, "Memory initialization failed at index %zu\n", i);
            free(memoryBlock);
            return;
        }
    }

    //-copilot next line-
}
```