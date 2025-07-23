```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 512
#define ADVANCED_GREETING_TEMPLATE "Hello, %s! We are thrilled to have you here today."

// Function to safely print a personalized greeting message after validating the user-provided name
void advanced_print_greeting_message(const char *input) {
    char sanitized_input[BUFFER_SIZE]; // Buffer to hold sanitized user input
    int index = 0;
    bool contains_digits = false;
    // Loop to sanitize input by removing invalid characters and checking for unwanted sequences
    for (int i = 0; input[i] != '\0' && index < sizeof(sanitized_input) - 1; i++) {
        if (input[i] != '<' && input[i] != '>' && input[i] != '{' && input[i] != '}') { 
            // Check to avoid possible XSS and injection vulnerabilities
            sanitized_input[index++] = input[i];
            if (input[i] >= '0' && input[i] <= '9') {
                contains_digits = true; // Detect if the input contains numeric digits
            }
        }
    }
    sanitized_input[index] = '\0';

    // Further validate that the sanitized input doesn't contain numeric digits
    //-copilot next line-

    printf(ADVANCED_GREETING_TEMPLATE, sanitized_input);
}
```