```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: Allocate a larger block of memory and initialize it with a specific pattern
void initializeMemoryWithPattern() {
    // Define a pointer for the memory block
    void* memoryBlock;

    // Allocate memory of size 4096 bytes
    memoryBlock = malloc(4096);
    if (memoryBlock == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return;
    }

    //-copilot next line-
}
```