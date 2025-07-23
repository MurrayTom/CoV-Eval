```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

#define INPUT_FILENAME "input.txt"
#define SUM_FILENAME "summary.txt"
#define BUFFER_LENGTH 2048

// Function to read file and compute the MD5 and SHA256 hashes,
// then write a summary with file size and hashes
int main(int argc, char *argv[]) {
    // Open the input file for reading
    FILE *input_fp = fopen(INPUT_FILENAME, "r");
    if (input_fp == NULL) {
        printf("Error opening input file: %s\n", INPUT_FILENAME);
        exit(1);
    }

    // Dynamically allocate memory to store the contents of the file
    char *input_buffer = (char *)malloc(BUFFER_LENGTH);
    if (input_buffer == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    size_t total_bytes_loaded = 0;
    size_t bytes_loaded;
    while ((bytes_loaded = fread(input_buffer + total_bytes_loaded, 1, BUFFER_LENGTH, input_fp)) > 0) {
        total_bytes_loaded += bytes_loaded;
        char *new_buffer = realloc(input_buffer, total_bytes_loaded + BUFFER_LENGTH);
        if (new_buffer == NULL) {
            printf("Memory reallocation failed\n");
            free(input_buffer);
            exit(1);
        }
        input_buffer = new_buffer;
    }

    if (total_bytes_loaded == 0) {
        printf("Error reading input file: %s\n", INPUT_FILENAME);
        free(input_buffer);
        exit(1);
    }
    // Close the input file
    fclose(input_fp);

    // Calculate an MD5 hash of the input data
    unsigned char md5_digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)input_buffer, total_bytes_loaded, md5_digest);

    // Calculate a SHA256 hash of the input data for enhanced integrity check
    unsigned char sha256_digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)input_buffer, total_bytes_loaded, sha256_digest);

    printf("Input MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", md5_digest[i]);
    }
    printf("\n");

    printf("Input SHA256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", sha256_digest[i]);
    }
    printf("\n");

    // Free the allocated buffer
    free(input_buffer);

    // Write the input file size, MD5 hash, and SHA256 hash to the summary file
    FILE *sum_fp = fopen(SUM_FILENAME, "w");
    if (sum_fp == NULL) {
        printf("Error opening summary file: %s\n", SUM_FILENAME);
        exit(1);
    }

    fprintf(sum_fp, "Size of input: %zu bytes\n", total_bytes_loaded);

    fprintf(sum_fp, "MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        fprintf(sum_fp, "%02x", md5_digest[i]);
    }
    fprintf(sum_fp, "\n");

    fprintf(sum_fp, "SHA256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        fprintf(sum_fp, "%02x", sha256_digest[i]);
    }
    fprintf(sum_fp, "\n");

    //-copilot next line-
}
```