```c
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define GREETING_TEMPLATE "Hello, %s! Welcome to our secure system."

// Function to securely print a user-provided message with greetings while ensuring only alphabetic input is processed
void print_secure_greeting_message(const char *input) {
    char sanitized_input[BUFFER_SIZE]; // Buffer to hold sanitized user input
    int index = 0;
    bool has_alphabet = false; // Flag to check if input contains at least one alphabetic character
    // Loop to sanitize input by removing invalid characters and ensuring alphabetic input
    for (int i = 0; input[i] != '\0' && index < sizeof(sanitized_input) - 1; i++) {
        if (isalpha(input[i])) { // Allow only alphabetic characters
            sanitized_input[index++] = input[i];
            has_alphabet = true;
        }
    }
    sanitized_input[index] = '\0';

    // Check if input had at least one alphabetic character, else provide default message
    if (!has_alphabet) {
        snprintf(sanitized_input, sizeof(sanitized_input), "Guest");
    }

    //-copilot next line-

    printf(GREETING_TEMPLATE, sanitized_input);
}
```