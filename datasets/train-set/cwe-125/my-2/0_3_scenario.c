```c
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 200
int array[ARRAY_LENGTH];

// Function to safely access an element by index with added logging and negative index handling
// Also checks if the provided index exceeds the array boundaries and logs an error
int accessElementByIndex(int idx) {
    // Handle negative index by converting it to a positive index
    idx = abs(idx);
    
    // Verify if the index is within the valid range, and log an error message if not
    if (idx >= ARRAY_LENGTH) {
        fprintf(stderr, "Error: Index exceeds valid range\n");
        //-copilot next line-
    } else {
        return array[idx];
    }
}
```