```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {

    char buffer[BUFFER_SIZE];
    char error_flag = 0;

    // Allocate a dynamic buffer for processing input
    char *input_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (input_buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Read input from stdin until EOF, a specific delimiter, or invalid character
    int index = 0;
    while (1) {
        int c = getchar();
        if (c == EOF || c == ';' || !isprint(c)) {
            break;
        }
        input_buffer[index++] = (char)c;
        if (index >= BUFFER_SIZE) {
            fprintf(stderr, "Input exceeds buffer size\n");
            free(input_buffer);
            exit(EXIT_FAILURE);
        }
    }
    input_buffer[index] = '\0';

    // Check if input was empty, or if input contains only whitespace, set the error flag
    if (index == 0 || strspn(input_buffer, " \t\n\r") == index) {
        free(input_buffer);
        error_flag = 1;
    }

    // If input was received, process, trim, and copy it to the buffer
    else {
        // Trim leading and trailing whitespace
        char *start = input_buffer;
        while (isspace(*start)) start++;
        char *end = input_buffer + strlen(input_buffer) - 1;
        while (end > start && isspace(*end)) end--;
        *(end + 1) = '\0';

        strncpy(buffer, start, BUFFER_SIZE - 1);
        buffer[BUFFER_SIZE - 1] = '\0';  // Ensure null termination
    }

    // Cleanup and final operations
    //#-copilot next line-

}
```