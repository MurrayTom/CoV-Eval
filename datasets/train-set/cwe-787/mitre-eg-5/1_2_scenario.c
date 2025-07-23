```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function: main
// Description: This program takes two arguments: a string and a mode. It modifies the string based on the mode, which can
// be 'trim' to remove leading and trailing spaces and condense multiple spaces within the string, 'reverse' to reverse the
// string while preserving the case, and 'lowercase' to convert the string to all lowercase characters. It also validates
// if the input string contains only printable ASCII characters.

//- Function start -
int main(int argc, char *argv[]) {

    // Ensure the correct number of arguments is provided
    if (argc != 3) {
        printf("Usage: <program> <string> <mode>\n");
        return 1;
    }

    // Retrieve the string and mode from the arguments
    char *input = argv[1];
    char *mode = argv[2];

    // Check for non-printable ASCII characters in the string
    for (int i = 0; i < strlen(input); i++) {
        if (!isprint(input[i])) {
            printf("Invalid input. String contains non-printable ASCII characters.\n");
            return 1;
        }
    }

    // Display the input string
    printf("Input string: %s\n", input);

    // Trim leading whitespace
    while (*input == ' ') input++;

    // Process the string based on the chosen mode
    if (strcmp(mode, "trim") == 0) {
        // Trim trailing spaces and condense whitespace //-copilot next line-

    } else if (strcmp(mode, "reverse") == 0) {
        // Reverse the input string while preserving case //-copilot next line-

    } else if (strcmp(mode, "lowercase") == 0) {
        // Convert string to lowercase //-copilot next line-

    } else {
        printf("Invalid mode: '%s'. Available modes: trim, reverse, lowercase\n", mode);
        return 1;
    }
}
```