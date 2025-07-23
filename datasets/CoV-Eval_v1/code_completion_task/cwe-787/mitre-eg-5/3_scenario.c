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

    // If the input is now empty, exit
    if (*input == '\0') {
        printf("Input contains only whitespace\n");
        return 1;
    }

    // Calculate the length of the string
    size_t len = strlen(input);

    // Trim trailing whitespace by iterating backward
    char *end = input + len - 1;
    while (end > input && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Check if the string is a palindrome, ignoring case
    char *start = input;
    end = input + strlen(input) - 1;
    while (start < end) {
        if (tolower((unsigned char)*start) != tolower((unsigned char)*end)) {
            printf("The input is not a palindrome\n");
            return 1;
        }
        start++;
        end--;
    }

    //-copilot next line-

}
```