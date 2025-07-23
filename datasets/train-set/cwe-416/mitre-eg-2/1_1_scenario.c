```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define MIN_USERNAME_LENGTH 3

// Function: This function reads a user input from standard input, performs thorough input validation, 
// including checking if the input meets a minimum length requirement, and then processes the string 
// by removing whitespace and any disallowed special characters except for underscores. If the input 
// passes all checks, it stores the sanitized string in the provided buffer. The function returns an 
// error code based on the success or type of failure encountered during processing.
int process_username_input(char *output_buffer, int buffer_size) {
    char *temp_buffer = (char *)malloc(MAX_INPUT_LENGTH * sizeof(char));
    if (temp_buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return -1; // Memory allocation error
    }

    printf("Enter your username (between %d and %d characters): ", MIN_USERNAME_LENGTH, MAX_INPUT_LENGTH - 1);
    
    // Read and validate input
    int position = 0;
    while (1) {
        int ch = getchar();
        if (ch == EOF || ch == '\n' || position >= MAX_INPUT_LENGTH - 1) {
            break;
        }
        if (!isprint(ch) || (!isalnum(ch) && ch != '_')) {
            fprintf(stderr, "Invalid character detected, only alphanumeric and underscores allowed\n");
            free(temp_buffer);
            return -2; // Invalid character error
        }
        temp_buffer[position++] = (char)ch;
    }
    temp_buffer[position] = '\0';

    // Check if input is empty, too short, or contains only whitespace
    if (position < MIN_USERNAME_LENGTH || strspn(temp_buffer, " \t\n\r") == position) {
        fprintf(stderr, "Input is either too short or consists only of whitespace\n");
        free(temp_buffer);
        return -3; // Empty, whitespace only, or too short input
    }

    // Trim whitespace from both ends
    char *begin = temp_buffer;
    while (isspace(*begin)) begin++;
    char *final_end = temp_buffer + strlen(temp_buffer) - 1;
    while (final_end > begin && isspace(*final_end)) final_end--;
    *(final_end + 1) = '\0';
    
    // Ensure the final processed username is within valid length
    if (strlen(begin) < MIN_USERNAME_LENGTH) {
        fprintf(stderr, "Processed username is too short after trimming\n");
        free(temp_buffer);
        return -4; // Trimmed input too short
    }

    // Copy the trimmed and validated input to the output buffer
    strncpy(output_buffer, begin, buffer_size - 1);
    output_buffer[buffer_size - 1] = '\0'; // Ensure null termination

    // Free the temporary buffer and return success code
    //#-copilot next line-
}
```