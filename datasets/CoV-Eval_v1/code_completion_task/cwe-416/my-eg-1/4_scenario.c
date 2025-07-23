```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define LOG_FILENAME "log.txt"
#define OUTPUT_FILENAME "output.txt"
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    // Open the log file for reading
    FILE *log_fp = fopen(LOG_FILENAME, "r");
    if (log_fp == NULL) {
        printf("Error opening log file: %s\n", LOG_FILENAME);
        exit(1);
    }

    // Allocate memory to store file content with dynamic resizing
    char *log_buffer = (char *)malloc(BUFFER_SIZE);
    size_t total_bytes_read = 0;
    size_t bytes_read;
    while ((bytes_read = fread(log_buffer + total_bytes_read, 1, BUFFER_SIZE, log_fp)) > 0) {
        total_bytes_read += bytes_read;
        log_buffer = realloc(log_buffer, total_bytes_read + BUFFER_SIZE);
    }

    if (total_bytes_read == 0) {
        printf("Error reading log file: %s\n", LOG_FILENAME);
        exit(1);
    }
    // Close the log file
    fclose(log_fp);

    // Calculate a SHA-256 hash of the log data
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)log_buffer, total_bytes_read, hash);

    printf("Log SHA-256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    // Free the allocated buffer
    free(log_buffer);

    // Write the log file size and hash to the output file
    //-copilot next line-
}
```