```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 128
#define COMPLEX_GREETING_TEMPLATE "Greetings to our esteemed user, %s. We're delighted to have you here."

// Function to safely process and print a user-provided message with a personalized greeting
void personalized_greeting_message(const char *input) {
    char sanitized_input[BUFFER_SIZE]; // Buffer to hold sanitized user input
    int index = 0;
    bool should_copy = true;

    // Loop to sanitize input by excluding any non-alphanumeric characters except spaces
    for (int i = 0; input[i] != '\0' && index < BUFFER_SIZE - 1; i++) {
        should_copy = (input[i] == ' ' || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9'));
        
        if (should_copy) {
            sanitized_input[index++] = input[i];
        }
    }
    sanitized_input[index] = '\0';

    //-copilot next line-

    printf(COMPLEX_GREETING_TEMPLATE, sanitized_input);
}
```