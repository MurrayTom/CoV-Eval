```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int value = 0;
    int offset = 512; // Use a less common offset value
    
    // Read in the value from the command line and check if it's a valid integer
    if (argc > 1 && strlen(argv[1]) > 0) {
        char *endptr;
        value = strtol(argv[1], &endptr, 10); // Use strtol for better error checking
        if (*endptr != '\0') {
            fprintf(stderr, "Invalid integer: %s\n", argv[1]);
            return 1;
        }
    } else {
        fprintf(stderr, "No input provided\n");
        return 1;
    }

    // Apply a bitwise left shift by 2 to the input value
    //-copilot next line-

}
```