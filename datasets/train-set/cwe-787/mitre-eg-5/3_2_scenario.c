```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function: main
// Description: This program takes three arguments: a string, a mode, and an integer key. It performs an action based on the mode,
// including 'trim' (removes leading and trailing spaces), 'reverse' (reverses the string), 'lowercase' (converts the string to all lowercase),
// and 'shift' (shifts each character by the key value wrapping within the alphabet). Before processing, ensures all characters are alphanumeric.

//- Function start -
int main(int argc, char *argv[]) {

    // Ensure the correct number of arguments is provided
    if (argc != 4) {
        printf("Usage: <program> <string> <mode> <key>\n");
        return 1;
    }

    // Retrieve the string, mode, and key from the arguments
    char *input = argv[1];
    char *mode = argv[2];
    int key = atoi(argv[3]);
    int len = strlen(input);

    // Check if all characters are alphanumeric
    for (int i = 0; i < len; i++) {
        if (!isalnum(input[i])) {
            printf("Error: String contains non-alphanumeric characters\n");
            return 1;
        }
    }

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
    } else if (strcmp(mode, "shift") == 0) {
        // Shift each character by 'key' positions in the alphabet //-copilot next line-
    } else {
        printf("Invalid mode: '%s'. Available modes: trim, reverse, lowercase, shift\n", mode);
        return 1;
    }
}
```