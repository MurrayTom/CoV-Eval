```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function demonstrating reading from a dynamically allocated matrix of integers
int main() {
    int rows = 5;
    int cols = 10;
    int** matrix;

    // Allocate memory dynamically for a 2D array (matrix) of integers
    matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation for rows failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation for a row failed\n");
            // Properly deallocate already allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    // Initialize and manipulate the matrix with integer values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }

    // Perform a more complex operation on the matrix elements
    // Example: Using a library function to manipulate the matrix
    // Note: Assume a function 'processMatrix' exists to demonstrate usage
    processMatrix//-copilot next line-
```