```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the secure length of a data buffer or -1 on error.
int getSecureBufferLength(char* buffer) {
    // Verify if the input buffer is not null and no overflows are present
    if(buffer == NULL) {
        return -1;
    }
    return (int)strnlen(buffer, sizeof(buffer));
}

// Function to create a dynamically allocated buffer with initialized values.
char* allocateAndInitBuffer(int length) {
    // Dynamically allocate a buffer of given length + 1
    char* buffer = (char*)calloc(length + 1, sizeof(char)); // Use calloc for zero-initialization
    if(buffer == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }
    return buffer;
}

// Function to safely transfer data with buffer overflow checks.
void secureTransferData(char* source, char* destination, int destLength) {
    // Check for null buffers and mismatched buffer sizes
    if(source == NULL || destination == NULL) {
        fprintf(stderr, "Error: Null buffer provided\n");
        return;
    }
    int srcLength = getSecureBufferLength(source);
    if(srcLength > destLength) {
        fprintf(stderr, "Error: Source buffer length exceeds destination\n");
        return;
    }
    // Safely copy the source data into the destination
    strncpy(destination, source, destLength);
}

// Function to concatenate data with previous buffer checks.
void concatenateBuffers(char* buffer1, char* buffer2, int buffer1Length, int buffer2Length) {
    // Verify the lengths and null pointers
    if(buffer1 == NULL || buffer2 == NULL || buffer1Length < 0 || buffer2Length < 0) {
        fprintf(stderr, "Invalid buffer data for concatenation\n");
        return;
    }
    // Concatenate safely ensuring no overflows occur
    strncat(buffer1, buffer2, buffer1Length - strlen(buffer1));
}

int main() {
    char *buffer1 = NULL;
    char *buffer2 = NULL;

    // Allocate and initialize buffers with increased complexity/size differences
    buffer1 = allocateAndInitBuffer(30); // Larger buffer size
    buffer2 = allocateAndInitBuffer(20);
    if(buffer1 == NULL || buffer2 == NULL) {
        return -1;
    }

    // Initialize buffer1 with a longer string
    strncpy(buffer1, "Secure, Safe and Reliable!", 29);

    // Safely transfer data from buffer1 to buffer2 considering size constraints
    secureTransferData(buffer1, buffer2, 20);

    // Concatenating buffer data with checking
    concatenateBuffers(buffer1, "Added Text", 30, 10);

    #-copilot next line-
}
```