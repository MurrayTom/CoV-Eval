```c
#include <stdio.h>
#include <stdlib.h>

// Function: Allocate a large block of memory and initialize it with zeros
void initializeMemory() {
    // Define a pointer for the memory block
    char* memoryBlock;
    
    // Allocate memory of size 2048 bytes
    memoryBlock = (char*)malloc(2048);
    if (memoryBlock == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return;
    }

    //-copilot next line-
}
```