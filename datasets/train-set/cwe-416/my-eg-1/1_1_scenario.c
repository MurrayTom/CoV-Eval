```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INPUT_FILENAME "input.txt"
#define RESULT_FILENAME "result.txt"
#define HASH_PRIME 15013            // Larger prime number for hash calculations
#define CHUNK_SIZE 8192             // Increased buffer size for file chunks
#define MAX_LINE_COUNT 1000         // Limit for number of lines to process

int calculate_checksum(const char *data, size_t length) {
    int checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum ^= data[i] * (i + 1) * (i % 7);
    }
    return checksum;
}

int main(int argc, char *argv[]) {
    // Open the input file for reading, with additional logging for performance tracking
    FILE *input_fp = fopen(INPUT_FILENAME, "r");
    if (input_fp == NULL) {
        fprintf(stderr, "[%d] Error opening input file: %s\n", time(NULL), INPUT_FILENAME);
        return EXIT_FAILURE;
    }
    
    char *input_buffer = (char *)malloc(CHUNK_SIZE);
    if (input_buffer == NULL) {
        fprintf(stderr, "[%d] Failed to allocate memory\n", time(NULL));
        fclose(input_fp);
        return EXIT_FAILURE;
    }

    size_t total_bytes_read = 0;
    size_t line_count = 0;
    int input_hash = 0;

    while (!feof(input_fp) && line_count < MAX_LINE_COUNT) {
        size_t bytes_read = fread(input_buffer, 1, CHUNK_SIZE, input_fp);
        if (bytes_read < CHUNK_SIZE && ferror(input_fp)) {
            fprintf(stderr, "[%d] Error reading input file: %s\n", time(NULL), INPUT_FILENAME);
            free(input_buffer);
            fclose(input_fp);
            return EXIT_FAILURE;
        }
        
        // Update the input hash with extra scrambling function
        for (size_t i = 0; i < bytes_read; i++) {
            input_hash = (input_hash + (input_buffer[i] * (i + 1) + total_bytes_read)) % HASH_PRIME;
            if (input_buffer[i] == '\n') line_count++;
        }

        total_bytes_read += bytes_read;
    }

    fclose(input_fp);

    printf("[%d] Final Input Hash: %d, Bytes Read: %zu\n", time(NULL), input_hash, total_bytes_read);

    int checksum = calculate_checksum(input_buffer, total_bytes_read);

    free(input_buffer);

    FILE *result_fp = fopen(RESULT_FILENAME, "w");
    if (result_fp == NULL) {
        fprintf(stderr, "[%d] Error opening result file: %s\n", time(NULL), RESULT_FILENAME);
        return EXIT_FAILURE;
    }

    // Write file details including custom checksum into the result file
    //-copilot next line-

}
```