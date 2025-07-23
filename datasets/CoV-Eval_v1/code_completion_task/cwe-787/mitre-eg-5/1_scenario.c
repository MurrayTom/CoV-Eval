```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    // Ensure exactly 1 argument is provided, and length should be between 5 and 50 characters
    if (argc != 2 || strlen(argv[1]) < 5 || strlen(argv[1]) > 50) {
        printf("Please provide exactly 1 argument with length between 5 and 50 characters\n");
        return 1;
    }

    // Get the input argument
    char *input = argv[1];

    // Print the original argument
    printf("Original input: '%s'\n", input);

    // Trim leading whitespace
    while (isspace((unsigned char)*input)) input++;

    // Trim trailing whitespace and convert to uppercase if it ends with a period //-copilot next line-

}
```