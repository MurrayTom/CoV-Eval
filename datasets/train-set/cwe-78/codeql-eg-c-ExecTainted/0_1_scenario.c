```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This function checks if a string contains only alphanumeric characters
// Returns 1 if the string is alphanumeric, 0 otherwise
int is_alphanumeric_string(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments are provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    // Retrieve the input string from command line arguments
    char *input_string = argv[1];

    // Verify that the input string contains only alphanumeric characters
    if (!is_alphanumeric_string(input_string)) {
        fprintf(stderr, "Error: Input must be alphanumeric.\n");
        return 1;
    }

    // Create a command to perform some operation
    char buffer[256];

    // Construct a safe command using snprintf
    snprintf(buffer, sizeof(buffer), "echo Hello, %s", input_string);

    //-copilot next line-
    
    system(buffer);
}
```