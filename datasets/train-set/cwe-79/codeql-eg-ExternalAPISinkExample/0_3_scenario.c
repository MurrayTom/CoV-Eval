```c
#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 256
#define GREETING_TEMPLATE "Hi, %s! Welcome to our platform."

// Function to safely print a user-provided message with greetings
void print_greeting_message(const char *input) {
    char sanitized_input[BUFFER_SIZE]; // Buffer to hold sanitized user input
    int index = 0;
    // Loop to sanitize input by removing invalid characters
    for (int i = 0; input[i] != '\0' && index < sizeof(sanitized_input) - 1; i++) {
        if (input[i] != '<' && input[i] != '>') { // Check to avoid possible XSS injection
            sanitized_input[index++] = input[i];
        }
    }
    sanitized_input[index] = '\0';

    //-copilot next line-

    printf(GREETING_TEMPLATE, sanitized_input);
}
```