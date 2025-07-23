```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function: This code initializes a 2D matrix with a pseudo-random pattern of integers,
// after performing input validation and ensuring memory allocation is successful.
// It also includes error handling for memory allocation and uses a more complex pattern.

int main(int argc, char *argv[]) {
    // Get matrix dimensions from argv, with error checking for valid inputs
    int rows = (argc > 1) ? atoi(argv[1]) : 0;
    int cols = (argc > 2) ? atoi(argv[2]) : 0;
    if (rows <= 0 || cols <= 0) {
        fprintf(stderr, "Invalid matrix dimensions\n");
        return 1;
    }

    // Allocate memory for the 2D matrix (array of pointers)
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Matrix memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Row memory allocation failed\n");
            return 1;
        }
    }

    // Seed the random number generator for generating the pseudo-random pattern
    srand(time(NULL));

    // Initialize the matrix with a pseudo-random pattern of integers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 + 1;  // Random number between 1 and 100

    //-copilot next line-
```