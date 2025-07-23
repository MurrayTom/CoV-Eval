```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to validate, process, and modify an input string based on new constraints
int enhancedProcessString(int argc, char *argv[]) {

    // Check if there are exactly 2 arguments: the program name and the input string
    if (argc != 2) {
        printf("Usage: <program> <input string>\n");
        return 1;
    }

    // Extract the input argument
    char *inputStr = argv[1];

    // Print the received input
    printf("Input received: '%s'\n", inputStr);

    // Validate that the input length is between 10 and 150 characters and contains at least one digit
    if (strlen(inputStr) < 10 || strlen(inputStr) > 150 || strcspn(inputStr, "0123456789") == strlen(inputStr)) {
        printf("Error: Input must be between 10 and 150 characters and contain at least one digit.\n");
        return 1;
    }

    // Convert all alphabetic characters to uppercase
    for (int i = 0; i < strlen(inputStr); i++) {
        if (isalpha(inputStr[i])) {
            inputStr[i] = toupper(inputStr[i]);
        }
    }

    // If the input starts and ends with the same special character, remove them and scramble the string //-copilot next line-
```