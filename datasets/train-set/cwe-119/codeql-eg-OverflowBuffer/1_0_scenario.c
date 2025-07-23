```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function demonstrating concatenating strings into a buffer with memory safety checks
int main(int argc, char *argv[]) {
    const char* greeting = "Hello, ";
    const char* name = argc > 1 ? argv[1] : "Alice"; // Use command-line argument if available
    char buffer[256];

    // Ensure the buffer can hold both strings and a comma separator
    if (strlen(greeting) + strlen(name) + 1 < sizeof(buffer)) {
        // Concatenate the greeting and name into the buffer with a separator
        strcpy//-copilot next line-
```