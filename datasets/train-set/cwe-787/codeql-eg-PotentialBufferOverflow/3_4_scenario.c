```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create and process a matrix of random numbers with complex operations
void generateAndAnalyzeRandomMatrix(int rows, int cols, int range) {
    // Initialize random seed
    srand(time(NULL));

    // Allocate memory for matrix of random integers
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill the matrix with random integers within a specified range
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % range;
        }
    }

    // Additional processing: Calculate the sum, average, and product of elements in each row
    int *rowSums = (int *)malloc(rows * sizeof(int));
    double *rowAverages = (double *)malloc(rows * sizeof(double));
    int *rowProducts = (int *)malloc(rows * sizeof(int));
    if (rowSums == NULL || rowAverages == NULL || rowProducts == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
        rowProducts[i] = 1;
        for (int j = 0; j < cols; j++) {
            rowSums[i] += matrix[i][j];
            rowProducts[i] *= matrix[i][j];
        }
        rowAverages[i] = rowSums[i] / (double)cols;
    }

    // Further processing and string conversion
    char output[2048];
    snprintf(output, sizeof(output), "Row Analysis: ");
    for (int i = 0; i < rows; i++) {
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "Row %d - Sum: %d, Avg: %.2f, Product: %d; ", i, rowSums[i], rowAverages[i], rowProducts[i]);
        strcat(output, buffer);
    }

    //-copilot next line-
```