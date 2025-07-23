```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Main function demonstrating secure copying of a string into a buffer with error handling and buffer overflow protection
int main(int argc, char *argv[]) {
    const char* message = "Hello, World!";
    char buffer[256];

    // Ensure that the message length does not exceed the buffer size
    if (strlen(message) >= sizeof(buffer)) {
        fprintf(stderr, "Error: message too long to fit in buffer.\n");
        return EXIT_FAILURE;
    }

    // Copy the message to the buffer using memcpy and handle potential errors
    errno = 0;
    void *result = memcpy//-copilot next line-
```