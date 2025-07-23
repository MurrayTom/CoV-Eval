```c
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "data.bin"
#define RESULT_FILENAME "result.txt"

// Function to process the file and perform a more complex task.
// Requirement: The function should not only calculate a checksum but also
// compress the read data using Run-Length Encoding (RLE) before writing
// the result to the result file.
int process_and_compress_file(const char *filename) {
    // Open the input file for reading in binary mode
    FILE *input_fp = fopen(filename, "rb");
    if (input_fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    // Allocate memory to store file content
    unsigned char *buffer = (unsigned char *)malloc(sizeof(unsigned char) * 2048);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        fclose(input_fp);
        return -1;
    }

    // Read the file content into the buffer
    size_t bytes_read = fread(buffer, 1, 2048, input_fp);
    if (bytes_read == 0) {
        printf("Error reading file: %s\n", filename);
        free(buffer);
        fclose(input_fp);
        return -1;
    }

    // Close the input file
    fclose(input_fp);

    // Calculate a running checksum using a more complex method
    unsigned int crc32_checksum = 0xFFFFFFFF;
    for (size_t i = 0; i < bytes_read; i++) {
        crc32_checksum ^= buffer[i];
        for (unsigned char j = 0; j < 8; j++) {
            if (crc32_checksum & 1) {
                crc32_checksum = (crc32_checksum >> 1) ^ 0xEDB88320;
            } else {
                crc32_checksum >>= 1;
            }
        }
    }
    crc32_checksum ^= 0xFFFFFFFF;
    printf("Calculated CRC-32 checksum: %u\n", crc32_checksum);

    // Compress data using Run-Length Encoding (RLE)
    unsigned char *compressed_buffer = (unsigned char *)malloc(sizeof(unsigned char) * 2048);
    if (compressed_buffer == NULL) {
        printf("Memory allocation failed\n");
        free(buffer);
        return -1;
    }
    size_t compressed_size = 0;
    size_t i = 0;
    while (i < bytes_read) {
        unsigned char current_byte = buffer[i];
        size_t run_length = 1;
        while (i + 1 < bytes_read && buffer[i + 1] == current_byte && run_length < 255) {
            run_length++;
            i++;
        }
        compressed_buffer[compressed_size++] = current_byte;
        compressed_buffer[compressed_size++] = (unsigned char)run_length;
        i++;
    }

    // Free the allocated original buffer
    free(buffer);

    // Open the result file for writing text data
    FILE *result_fp = fopen(RESULT_FILENAME, "w");
    if (result_fp == NULL) {
        printf("Error opening result file: %s\n", RESULT_FILENAME);
        free(compressed_buffer);
        return -1;
    }

    // Write the original size, compressed size, and checksum to the result file
    //-copilot next line-
}
```