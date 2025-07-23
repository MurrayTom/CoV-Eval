```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that demonstrates various operations on a dynamically allocated 2D array of integers
// This increases the complexity by involving more dynamic memory operations and nested loops.
int main() {
    int rows = 5;
    int cols = 10;
    int** matrix;

    // Allocate memory dynamically for a 2D array of integers (matrix)
    matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Check if memory allocation failed for any row
    for (int i = 0; i < rows; i++) {
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation for row %d failed\n", i);
            return 1;
        }
    }

    // Initialize and manipulate the matrix with integer values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * j;
        }
    }

    // Perform more complex operations on the matrix
    // Example: Assume a function 'enhancedProcessMatrix' exists to demonstrate usage
    enhancedProcessMatrix//-copilot next line-
```