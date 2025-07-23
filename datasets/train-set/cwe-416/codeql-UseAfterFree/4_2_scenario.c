```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: This code initializes a 2D matrix with a pattern based on the sum of its indices,
// after verifying the input dimensions. It also utilizes dynamic memory allocation for the matrix storage.

int main(int argc, char *argv[]) {
    // Get matrix dimensions from argv, with error checking for valid input
    int rows = (argc > 1) ? atoi(argv[1]) : 0;
    int cols = (argc > 2) ? atoi(argv[2]) : 0;
    if (rows <= 0 || cols <= 0) {
        fprintf(stderr, "Invalid matrix dimensions\n");
        return 1;
    }

    // Allocate memory for the 2D matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Matrix row allocation failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Matrix column allocation failed\n");
            return 1;
        }
    }

    // Initialize the matrix with a pattern where each element is the sum of its indices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;

    //-copilot next line-
```