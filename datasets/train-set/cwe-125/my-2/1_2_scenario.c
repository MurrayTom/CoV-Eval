```c
#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 100
#define INVALID_RESULT -1

char buffer[BUFFER_SIZE];

// Function to fetch a character from the buffer by index with enhanced bounds checking
// The function ensures that the index is a multiple of five and not a boundary value, returning an invalid result otherwise.
char getCharByQuintupleIndexNonBoundary(int index) {
    // Ensure the index is within bounds, is a multiple of five, and not at the beginning or end of buffer
    //-copilot next line-
}

int main() {
    int index;
    printf("Enter an index that is a multiple of five and not at boundaries: ");
    scanf("%d", &index);
    return getCharByQuintupleIndexNonBoundary(index);
}
```