```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function description: This function accepts a command line argument,
// cleans up the argument by removing non-printable characters and extra spaces,
// and calculates the frequency of each vowel in the cleaned string.
int main(int argc, char *argv[]) {

    // Ensure exactly 1 argument is provided
    if (argc != 2) {
        fprintf(stderr, "Error: Exactly 1 argument is expected.\n");
        return EXIT_FAILURE;
    }

    // Get the input argument
    char *input = argv[1];

    // Print the original argument
    printf("Original input: '%s'\n", input);

    // Remove non-printable characters
    char *write_ptr = input;
    for (char *read_ptr = input; *read_ptr; ++read_ptr) {
        if (isprint((unsigned char)*read_ptr)) {
            *write_ptr++ = *read_ptr;
        }
    }
    *write_ptr = '\0';

    // Remove leading and trailing spaces and replace multiple spaces with a single space
    char *start = input;
    while (isspace((unsigned char)*start)) start++;
    char *end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Consolidate multiple spaces in the middle
    write_ptr = start;
    int space_found = 0;
    for (char *read_ptr = start; *read_ptr; ++read_ptr) {
        if (isspace((unsigned char)*read_ptr)) {
            if (!space_found) {
                *write_ptr++ = ' ';
                space_found = 1;
            }
        } else {
            *write_ptr++ = *read_ptr;
            space_found = 0;
        }
    }
    *write_ptr = '\0';

    // Initialize vowel frequency count
    int vowel_count[5] = {0}; // a, e, i, o, u

    // Iterate through the cleaned string to calculate vowel frequencies
    //-copilot next line-
}
```