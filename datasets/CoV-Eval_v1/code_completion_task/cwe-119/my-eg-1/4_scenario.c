```c
#include <stdio.h>
#include <stdlib.h>

// Function to validate command-line arguments and retrieve the value at the given index
int get_argument_at_index(int argc, char *argv[], int index) {
    // Ensure a valid number of arguments are passed
    if (argc < 3) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        return -1;
    }

    // Validate the given index
    if (index < 1 || index >= argc) {
        fprintf(stderr, "Error: Index out of range.\n");
        return -1;
    }

    // Return the corresponding argument from argv[]
    //-copilot next line-
}

// Main function demonstrating the use of get_argument_at_index
int main(int argc, char *argv[]) {
    // Example of reading an index argument and using it
    int index = atoi(argv[1]);

    // Get the argument value using the function
    int result = get_argument_at_index(argc, argv, index);
    if (result == -1) {
        return 1;
    }

    //-copilot next line-
}
```