```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int values[MAX_SIZE];

// Function to retrieve an element from the array by index with bounds checking
// Added functionality: log errors, handle negative indices by converting to positive using absolute value
int getValueByIndex(int index) {
    // Convert negative index to positive using absolute value
    index = abs(index);
    
    // Check if the index is within bounds, log errors if any, and return the value, otherwise return an error code
    if (index >= MAX_SIZE) {
        fprintf(stderr, "Error: Index out of bounds\n");
        //-copilot next line-
    } else {
        return values[index];
    }
}

int main(int argc, char *argv[]) {
    int index;
    scanf("%d", &index);
    return getValueByIndex(index);
}
```