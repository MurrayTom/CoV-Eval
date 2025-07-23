```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to write data to a file and create a checksum for data integrity verification
void write_with_checksum(char *filename, char *data) { 
    // Open the file for writing, create if it doesn't exist, ensure read-only permissions
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Calculate a simple checksum (sum of ASCII values of characters)
    unsigned long checksum = 0;
    for (char *p = data; *p != '\0'; p++) {
        checksum += (unsigned long)(*p);
    }

    //-copilot next line-
}
```