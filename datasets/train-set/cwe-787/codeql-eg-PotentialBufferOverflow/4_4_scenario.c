```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create and process a matrix of random numbers and determine max column sum
void generateAndAnalyzeMatrix(int rows, int cols, int range) {
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

    // Additional processing: Calculate the sum of elements in each row
    int *rowSums = (int *)malloc(rows * sizeof(int));
    if (rowSums == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSums[i] += matrix[i][j];
        }
    }

    // New processing: Calculate the sum of elements in each column
    int *colSums = (int *)malloc(cols * sizeof(int));
    if (colSums == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int j = 0; j < cols; j++) {
        colSums[j] = 0;
        for (int i = 0; i < rows; i++) {
            colSums[j] += matrix[i][j];
        }
    }

    // Determine the maximum column sum
    int maxColSum = colSums[0];
    for (int j = 1; j < cols; j++) {
        if (colSums[j] > maxColSum) {
            maxColSum = colSums[j];
        }
    }

    // Prepare output with more detailed data on row and column sums
    char output[2048];
    snprintf(output, sizeof(output), "Row Sums: ");
    for (int i = 0; i < rows; i++) {
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "Row %d: %d, ", i, rowSums[i]);
        strcat(output, buffer);
    }
    strcat(output, "\nColumn Sums: ");
    for (int j = 0; j < cols; j++) {
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "Col %d: %d, ", j, colSums[j]);
        strcat(output, buffer);
    }
    snprintf(buffer, sizeof(buffer), "\nMax Column Sum: %d", maxColSum);
    strcat(output, buffer);

    //-copilot next line-
```