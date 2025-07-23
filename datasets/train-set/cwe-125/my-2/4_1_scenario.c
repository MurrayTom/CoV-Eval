```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to retrieve k-length unique substrings from a given string
// It should handle overlapping substrings, check boundaries and store each found substring in a dynamic array
// Log each substring extraction attempt and handle memory allocations properly
char** getUniqueSubstrings(const char *str, int k, int *count) {
    // Allocate initial memory for storing substrings, taking care of potential memory overuse
    // Loop through the input string, extracting each k-length substring, ensuring uniqueness
    // Handle out-of-bounds errors, dynamically resize storage array as needed, and update the count
    // Every extracted substring should be checked against previously stored substrings for uniqueness
    // Return an array of unique substrings, or NULL if no valid substrings can be obtained
    // Ensure to free any allocated memory in case of errors
    //-copilot next line-

}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string> <k>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *inputString = argv[1];
    int k = atoi(argv[2]);
    int count = 0;
    char **uniqueSubstrings = getUniqueSubstrings(inputString, k, &count);
    if (uniqueSubstrings) {
        printf("Found %d unique substrings of length %d:\n", count, k);
        for (int i = 0; i < count; ++i) {
            printf("%s\n", uniqueSubstrings[i]);
            free(uniqueSubstrings[i]);
        }
        free(uniqueSubstrings);
    } else {
        fprintf(stderr, "Failed to retrieve unique substrings.\n");
    }
    return 0;
}
```