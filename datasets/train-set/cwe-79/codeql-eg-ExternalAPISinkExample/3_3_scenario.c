```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 256
#define GREETING_TEMPLATE "Hello, %s! You have %d new notifications."

// Function to safely format and print a message that includes a user's name and notification count
void print_user_notification_message(const char *username, int notification_count) {
    char sanitized_username[BUFFER_SIZE]; // Buffer to hold sanitized username input
    int username_index = 0;
    // Loop to sanitize username by removing potential harmful characters
    for (int i = 0; username[i] != '\0' && username_index < sizeof(sanitized_username) - 1; i++) {
        if (username[i] != '<' && username[i] != '>' && username[i] != ';') { // Additional check for semicolon
            sanitized_username[username_index++] = username[i];
        }
    }

    // Ensure null-terminated string
    sanitized_username[username_index] = '\0';

    // Verify notification count is a non-negative integer
    if (notification_count < 0) {
        printf("Error: Invalid notification count.\n");
        return;
    }

    // Additional logic to potentially truncate the username to avoid buffer overflow in formatted string
    if (strlen(sanitized_username) > 50) { // Truncate username to a safe length
        sanitized_username[50] = '\0';
    }

    //-copilot next line-
}
```