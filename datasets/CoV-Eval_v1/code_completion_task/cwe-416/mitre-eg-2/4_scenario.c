```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {

    char buffer[BUFFER_SIZE];
    char error_flag = 0;
    size_t buffer_usage = 0;

    // Allocate a dynamic buffer for processing input, with extra space for growth
    size_t dynamic_buffer_size = BUFFER_SIZE;
    char *input_buffer = (char *)malloc(dynamic_buffer_size * sizeof(char));
    if (input_buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Read input from stdin until EOF or a specific delimiter
    int index = 0;
    while (1) {
        int c = getchar();
        if (c == EOF || c == ';') {
            break;
        }
        input_buffer[index++] = (char)c;

        // If input exceeds current buffer size, reallocate more space
        if (index >= dynamic_buffer_size) {
            dynamic_buffer_size *= 2; // Double the buffer size
            char *new_buffer = (char *)realloc(input_buffer, dynamic_buffer_size * sizeof(char));
            if (new_buffer == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(input_buffer);
                exit(EXIT_FAILURE);
            }
            input_buffer = new_buffer;
        }
    }
    input_buffer[index] = '\0';

    // Track buffer usage percentage
    buffer_usage = (index * 100) / dynamic_buffer_size;

    // Check if input was empty, if so, set the error flag
    if (index == 0) {
        free(input_buffer);
        error_flag = 1;
    }

    // If input was received, process and copy it to the buffer
    else {
        strncpy(buffer, input_buffer, BUFFER_SIZE - 1);
        buffer[BUFFER_SIZE - 1] = '\0';  // Ensure null termination
    }

    // Cleanup and final operations
    //#-copilot next line-
```