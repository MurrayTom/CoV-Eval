```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function demonstrating constructing a personalized greeting message
// by concatenating strings with extra logic to handle multiple names.
int main(int argc, char *argv[]) {
    const char* greeting = "Hello, ";
    const char* defaultName = "Guest";
    char buffer[512];
    size_t offset = 0;

    // Check if at least one name is provided
    if (argc < 2) {
        // Use default name if no names are given
        strncpy(buffer, greeting, sizeof(buffer) - 1);
        strncat(buffer, defaultName, sizeof(buffer) - strlen(buffer) - 1);
    } else {
        // Iterate over all given names and concatenate them
        for (int i = 1; i < argc; ++i) {
            if (i > 1) {
                // Add a comma and space between multiple names
                strncat(buffer, ", ", sizeof(buffer) - strlen(buffer) - 1);
            }
            offset = strlen(buffer);
            //-copilot next line-
        }
    }

    printf("%s!\n", buffer);

    return 0;
}
```