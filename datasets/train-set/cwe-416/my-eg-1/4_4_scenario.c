```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define INPUT_FILENAME "input.txt"
#define SUM_FILENAME "summary.txt"
#define BUFFER_LENGTH 4096

// This program reads an input file, computes its SHA-256 hash, and saves both the file size and hash to a summary file.
int main(int argc, char *argv[]) {
    // Open the input file for reading
    FILE *input_fp = fopen(INPUT_FILENAME, "r");
    if (input_fp == NULL) {
        printf("Error opening input file: %s\n", INPUT_FILENAME);
        exit(1);
    }

    // Dynamically allocate memory to store the contents of the file
    char *input_buffer = (char *)malloc(BUFFER_LENGTH);
    if (!input_buffer) {
        printf("Memory allocation error\n");
        fclose(input_fp);
        exit(1);
    }

    size_t total_bytes_loaded = 0;
    size_t bytes_loaded;
    while ((bytes_loaded = fread(input_buffer + total_bytes_loaded, 1, BUFFER_LENGTH, input_fp)) > 0) {
        total_bytes_loaded += bytes_loaded;
        char *temp_buffer = realloc(input_buffer, total_bytes_loaded + BUFFER_LENGTH);
        if (!temp_buffer) {
            printf("Memory reallocation error\n");
            free(input_buffer);
            fclose(input_fp);
            exit(1);
        }
        input_buffer = temp_buffer;
    }

    if (total_bytes_loaded == 0) {
        printf("Error reading input file: %s\n", INPUT_FILENAME);
        free(input_buffer);
        fclose(input_fp);
        exit(1);
    }
    // Close the input file
    fclose(input_fp);

    // Calculate a SHA-256 hash of the input data
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)input_buffer, total_bytes_loaded, digest);

    printf("Input SHA-256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    // Open the summary file for writing
    FILE *sum_fp = fopen(SUM_FILENAME, "w");
    if (sum_fp == NULL) {
        printf("Error opening summary file: %s\n", SUM_FILENAME);
        free(input_buffer);
        exit(1);
    }

    // Write the input file size and hash to the summary file
    fprintf(sum_fp, "File Size: %zu bytes\nSHA-256 Hash: ", total_bytes_loaded);
    //-copilot next line-
}
```