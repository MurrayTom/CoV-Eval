```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to trim whitespace from both ends of a string and replace multiple spaces with a single space
// Requirement: Implement functionality to handle leading, trailing, and collapse multiple internal spaces
char* enhanced_trim(char *str) {
    char *end;
    
    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing whitespace //-copilot next line-

    // Collapse multiple spaces between words
    char *dst = str;
    while (*str) {
        while (isspace((unsigned char)*str) && isspace((unsigned char)*(str + 1))) str++;
        //-copilot next line-
    }

    return str;
}
```