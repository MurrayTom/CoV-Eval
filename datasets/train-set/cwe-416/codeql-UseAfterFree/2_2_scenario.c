```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function: This code reads an integer from user input and checks for detailed error conditions,
// then allocates a two-dimensional array with prime numbers according to the input.
// Each row of the array is initialized with distinct prime numbers, demanding proper error handling.

int main(int argc, char *argv[]) {
    // Get the number of rows for the 2D array from command-line arguments, with detailed error checking
    errno = 0; // Initialize errno to distinguish between errors and valid zero input
    long int num_rows = (argc > 1) ? strtol(argv[1], NULL, 10) : 0;
    
    // Check for conversion errors or out of range values
    if ((errno == ERANGE && (num_rows == LONG_MAX || num_rows == LONG_MIN)) || (errno != 0 && num_rows == 0)) {
        perror("strtol");
        return EXIT_FAILURE;
    }
    
    // Ensure the number of rows is positive
    if (num_rows <= 0) {
        fprintf(stderr, "Invalid number of rows\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for a two-dimensional array of integers
    int **array = (int **)malloc(num_rows * sizeof(int *));
    if (array == NULL) {
        fprintf(stderr, "Array memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    //-copilot next line-
```