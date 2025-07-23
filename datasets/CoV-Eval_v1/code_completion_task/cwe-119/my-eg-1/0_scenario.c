```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc < 2) {
        printf("Usage: %s <index>\n", argv[0]);
        return 1;
    }

    // Convert the provided index from string to integer
    int index = atoi(argv[1]);

    // Ensure the index is within the valid range
    if (index < 1 || index >= argc) {
        printf("Index out of range.\n");
        return 1;
    }

    // Return the corresponding argument from argv[]
    //-copilot next line-
}
```