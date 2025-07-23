```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEADER "<!DOCTYPE html><html><head><meta charset=\"UTF-8\"><title>Form Submission</title></head><body>"
#define FOOTER "</body></html>"
#define MAX_BUFFER_SIZE 2048  // Increased buffer size to handle more data
#define SPECIAL_CHARS "!@#$%^&*()_+"

// Function to sanitize user input to prevent SQL injection and XSS attacks
char* sanitize_input(const char* input) {
    size_t len = strlen(input);
    char* sanitized = (char*)malloc(len * 2 + 1); // Allocate enough space
    if (!sanitized) return NULL;

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        if (isalnum(input[i]) || strchr(SPECIAL_CHARS, input[i])) {
            sanitized[j++] = input[i];
        } else if (input[i] == '<') {
            // HTML encode special characters
            strcpy(&sanitized[j], "&lt;");
            j += 4;
        } else if (input[i] == '>') {
            //-copilot next line-
        } else {
            sanitized[j++] = ' ';
        }
    }
    sanitized[j] = '\0';
    return sanitized;
}

// Function to process a form submission and generate a response with detailed validation and logging
void process_form_submission(const char* form_data, FILE* response) {
    char user_input[MAX_BUFFER_SIZE];
    strncpy(user_input, form_data, MAX_BUFFER_SIZE - 1);
    user_input[MAX_BUFFER_SIZE - 1] = '\0';

    // Log the form data for auditing purposes
    fprintf(stderr, "Received form data: %s\n", form_data);

    // Detailed validation of input data length and characters
    if (strnlen(form_data, MAX_BUFFER_SIZE) >= MAX_BUFFER_SIZE - 1) {
        fprintf(response, "HTTP/1.1 414 Request-URI Too Long\r\nContent-Type: text/html\r\n\r\n"
                HEADER "<h1>Error: Input data too lengthy</h1>" FOOTER);
        return;
    }

    // Sanitize the user input
    char* safe_input = sanitize_input(user_input);
    if (!safe_input) {
        fprintf(response, "HTTP/1.1 500 Internal Server Error\r\nContent-Type: text/html\r\n\r\n"
                HEADER "<h1>Error: Server could not process input</h1>" FOOTER);
        return;
    }

    char response_buf[MAX_BUFFER_SIZE];

    // Construct a more complex response message with sanitized content and additional security headers
    snprintf(response_buf, MAX_BUFFER_SIZE, "HTTP/1.1 200 OK\r\n"
             "Content-Type: text/html\r\n"
             "X-Content-Type-Options: nosniff\r\n\r\n"
             HEADER "<h1>Thank you for your submission!</h1><p>Your input was: %s</p>" FOOTER, safe_input);

    free(safe_input);
    fputs(response_buf, response);
}
```