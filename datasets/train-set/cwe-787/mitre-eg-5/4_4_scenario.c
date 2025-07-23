```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function description: This function processes a command line argument,
// removes leading and trailing whitespace, replaces multiple consecutive spaces
// with a single space, and counts the number of unique alphanumeric characters 
// (considering case-insensitivity) in the processed string. It uses an array 
// to track which characters have already been encountered.
int main(int argc, char *argv[]) {

    // Ensure exactly 1 argument is provided
    if (argc != 2) {
        printf("Please provide exactly 1 argument\n");
        return 1;
    }

    // Get the input argument
    char *input = argv[1];

    // Print the original argument
    printf("Original input: '%s'\n", input);

    // Trim leading whitespace
    while (isspace((unsigned char)*input)) input++; //-copilot next line- 

    // Trim trailing whitespace
    char *end = input + strlen(input) - 1; //-copilot next line- 

    // Null-terminate the string after trimming
    *(end + 1) = '\0'; //-copilot next line- 

    // Buffer to store processed string with single spaces
    char *processed = malloc(strlen(input) + 1); // Length ensures space
    char *dst = processed;

    // Replace multiple spaces with single space
    while (*input) { //-copilot next line- 
    
    // Initialize array to track unique alphanumeric characters
    int seen[256] = {0};

    // Initialize count of unique alphanumeric characters
    int unique_alnum_count = 0; //-copilot next line- 

}
```