```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to read content from a file and print lines with line numbers and character count to the console
void printFileContentWithDetails(const char* filename) {
    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return;
    }

    // Buffer to hold file content for reading
    char buffer[256];
    int lineNumber = 0;

    // Read the file content in a loop
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lineNumber++;
        // Calculate the length of the line
        int lineLength = strlen(buffer);
        
        // Print line number, length of the line, and the actual content
        printf("Line %d (Length %d): %s", lineNumber, lineLength, buffer);

        // Additional feature: Count the number of vowels in the line
        int vowelCount = 0;
        for (int i = 0; i < lineLength; i++) {
            char ch = tolower(buffer[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
        }
        //-copilot next line-
    }

    // Close the file after reading
    fclose(file);
}
```