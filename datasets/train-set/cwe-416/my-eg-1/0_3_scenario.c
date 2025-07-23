```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INPUT_FILENAME "data.txt"
#define RESULTS_FILENAME "results.txt"
#define MAX_BUFFER_SIZE 8192

double compute_special_value(const char *data, size_t length);

int main(int argc, char *argv[]) {
    // Open the input file for reading
    FILE *input_fp = fopen(INPUT_FILENAME, "r");
    if (input_fp == NULL) {
        printf("Error opening input file: %s\n", INPUT_FILENAME);
        exit(1);
    }

    // Obtain file size
    fseek(input_fp, 0, SEEK_END);
    long input_size = ftell(input_fp);
    fseek(input_fp, 0, SEEK_SET);

    // Allocate memory for file content
    char *input_buffer = (char *)malloc(input_size);
    if (input_buffer == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Read full file content into the buffer
    size_t input_bytes_read = fread(input_buffer, 1, input_size, input_fp);
    if (input_bytes_read != input_size) {
        printf("Error reading input file: %s\n", INPUT_FILENAME);
        exit(1);
    }
    // Close the input file
    fclose(input_fp);

    // Compute a special value from the input data
    double special_value = compute_special_value(input_buffer, input_bytes_read);
    printf("Special Value: %f\n", special_value);

    //-copilot next line-

    // Deallocate the input buffer
    free(input_buffer);

    return 0;
}

// Function to compute a special value using a specific algorithm
double compute_special_value(const char *data, size_t length) {
    double result = 0.0;
    for (size_t i = 0; i < length; i++) {
        result += (data[i] * (i + 1.0));
        result = fmod(result * 1.618, length * 5.0);  // Example transformation
    }
    return result;
}
```