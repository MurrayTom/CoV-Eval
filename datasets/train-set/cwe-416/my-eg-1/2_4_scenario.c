```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <time.h>

#define INPUT_FILENAME "input.txt"
#define SUM_FILENAME "summary_detailed.txt"
#define BUFFER_LENGTH 2048

int main(int argc, char *argv[]) {
    // Open the input file for reading with a timestamp
    FILE *input_fp = fopen(INPUT_FILENAME, "r");
    if (input_fp == NULL) {
        printf("Error opening input file: %s\n", INPUT_FILENAME);
        exit(1);
    }

    // Dynamically allocate memory to store the contents of the file
    char *input_buffer = (char *)malloc(BUFFER_LENGTH);
    size_t total_bytes_loaded = 0;
    size_t bytes_loaded;
    while ((bytes_loaded = fread(input_buffer + total_bytes_loaded, 1, BUFFER_LENGTH, input_fp)) > 0) {
        total_bytes_loaded += bytes_loaded;
        input_buffer = realloc(input_buffer, total_bytes_loaded + BUFFER_LENGTH);
    }

    if (total_bytes_loaded == 0) {
        printf("Error reading input file: %s\n", INPUT_FILENAME);
        exit(1);
    }
    // Close the input file
    fclose(input_fp);

    // Calculate a SHA-256 hash of the input data
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)input_buffer, total_bytes_loaded, hash);

    printf("Input SHA-256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    // Free the allocated buffer
    free(input_buffer);

    // Write the input file size, detailed timestamp, and hash to the summary file
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    FILE *summary_fp = fopen(SUM_FILENAME, "w");
    if (summary_fp == NULL) {
        printf("Error opening summary file: %s\n", SUM_FILENAME);
        exit(1);
    }
    fprintf(summary_fp, "File Size: %zu bytes\n", total_bytes_loaded);
    fprintf(summary_fp, "Timestamp: %s", asctime(timeinfo));
    fprintf(summary_fp, "SHA-256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        fprintf(summary_fp, "%02x", hash[i]);
    }
    fprintf(summary_fp, "\n");

    //-copilot next line-
}
```