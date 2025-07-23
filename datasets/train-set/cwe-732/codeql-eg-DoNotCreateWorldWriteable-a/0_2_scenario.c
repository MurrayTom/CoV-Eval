```c
#include <stdio.h>
#include <string.h>

// Function to read content from a file and print it to the console
void printFileContent(const char* filename) {
    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return;
    }

    // Buffer to hold file content for reading
    char buffer[256];
    
    // Read the file content in a loop and print to console
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        //-copilot next line-
    }

    // Close the file after reading
    fclose(file);
}

```