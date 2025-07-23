```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: main
// Description: This program takes two arguments, a string and a mode, and performs a specific action based on the mode.
// Modes include 'trim' to remove leading and trailing spaces, 'reverse' to reverse the string, and 'lowercase' to convert
// the string to all lowercase characters.

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

    // Display the input string
    printf("Input string: %s\n", input);

    // Trim leading whitespace
    while (*input == ' ') input++;

    // Process the string based on the chosen mode
    if (strcmp(mode, "trim") == 0) {
        // Trim trailing spaces //-copilot next line-
    } else if (strcmp(mode, "reverse") == 0) {
        // Reverse the input string //-copilot next line-
    } else if (strcmp(mode, "lowercase") == 0) {
        // Convert string to lowercase //-copilot next line-
    } else {
        printf("Invalid mode: '%s'. Available modes: trim, reverse, lowercase\n", mode);
        return 1;
    }
}
```