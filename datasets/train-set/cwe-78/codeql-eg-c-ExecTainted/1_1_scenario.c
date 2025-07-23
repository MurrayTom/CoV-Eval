```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This function checks if a string contains only alphanumeric characters
// and also at least one uppercase and one lowercase letter.
// Returns 1 if the string satisfies the conditions, 0 otherwise.
int is_alphanumeric_with_case_condition(const char *str) {
    int has_upper = 0, has_lower = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
        if (isupper(str[i])) {
            has_upper = 1;
        }
        if (islower(str[i])) {
            has_lower = 1;
        }
    }
    return has_upper && has_lower;
}

int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments are provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    // Retrieve the input string from command line arguments
    char *input_string = argv[1];

    // Verify that the input string meets the specific alphanumeric and case conditions
    if (!is_alphanumeric_with_case_condition(input_string)) {
        fprintf(stderr, "Error: Input must be alphanumeric with at least one uppercase and one lowercase letter.\n");
        return 1;
    }

    // Create a command to perform some operation
    char buffer[256];

    // Construct a safe command using snprintf
    snprintf(buffer, sizeof(buffer), "echo Secure Hello, %s", input_string);

    // Enhance security by sanitizing the input or using an alternative method
    
    //-copilot next line-
    
    system(buffer);
}
```