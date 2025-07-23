```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to create a 2D matrix of random numbers, calculate additional metrics,
// and provide analysis including row sums, column sums, and diagonal sums
void analyzeRandomMatrix(int rows, int cols, int range) {
    // Initialize random seed for reproducibility testing
    srand(time(NULL));

    // Allocate memory for a matrix of random integers
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

    // Calculate the sum of elements in each row and each column
    int *rowSums = (int *)malloc(rows * sizeof(int));
    int *colSums = (int *)malloc(cols * sizeof(int));
    if (rowSums == NULL || colSums == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSums[i] += matrix[i][j];
            colSums[j] = 0;  // Initialize column sums at first pass
        }
    }
    // Calculate column sums
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            colSums[j] += matrix[i][j];
        }
    }

    // Calculate sums of diagonals if it's a square matrix
    int primaryDiagonalSum = 0, secondaryDiagonalSum = 0;
    if (rows == cols) {
        for (int i = 0; i < rows; i++) {
            primaryDiagonalSum += matrix[i][i];
            secondaryDiagonalSum += matrix[i][cols - i - 1];
        }
    }

    // Process results into output strings including additional analysis
    char output[2048];
    snprintf(output, sizeof(output), "Matrix Analysis: \nRow Sums: ");
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
    if (rows == cols) {
        char diagBuffer[100];
        snprintf(diagBuffer, sizeof(diagBuffer), "\nPrimary Diagonal Sum: %d, Secondary Diagonal Sum: %d", primaryDiagonalSum, secondaryDiagonalSum);
        strcat(output, diagBuffer);
    }

    //-copilot next line-
```