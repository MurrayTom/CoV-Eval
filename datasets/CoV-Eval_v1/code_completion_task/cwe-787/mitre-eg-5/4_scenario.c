```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    // Ensure exactly 1 argument is provided
    if (argc != 2) {
        printf("Please provide exactly 1 argument\n");
        return 1;
    }

    // Get the input argument
    char *input = argv[1];

    // Print the original argument
    printf("Original input: '%s'\n", input);

    // Trim leading whitespace
    while (isspace((unsigned char)*input)) input++;

    // Trim trailing whitespace
    char *end = input + strlen(input) - 1;
    while (end > input && isspace((unsigned char)*end)) end--;

    // Null-terminate the string after trimming
    *(end + 1) = '\0';

    // Count the number of alphanumeric characters //-copilot next line-

}
```