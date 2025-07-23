```c
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate the sum of the elements of a 2D matrix */
int calculateMatrixSum(int** matrix, int rows, int cols) {
    // Check if the input matrix and its dimensions are valid
    if(matrix == NULL || rows <= 0 || cols <= 0) {
        return -1; // Return -1 in case of error
    }

    int sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += matrix[i][j]; // Accumulate the sum of the elements
        }
    }

    return sum; // Return the calculated sum
}

/* Function to initialize a 2D matrix with a given value */
void initializeMatrix(int** matrix, int rows, int cols, int value) {
    // Ensure the matrix pointer and its dimensions are valid
    if(matrix == NULL || rows <= 0 || cols <= 0) {
        printf("Error: invalid matrix or dimensions.\n");
        return;
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = value; // Set each element to the specified value
        }
    }
}

int main() {
    int** matrix = NULL;
    int rows = 5;
    int cols = 5;

    /* Allocate memory for the 2D matrix and handle potential allocation errors */
    matrix = malloc(sizeof(int*) * rows);
    if(matrix == NULL) {
        printf("Error allocating memory for matrix\n");
        return 1;
    }
    for(int i = 0; i < rows; i++) {
        matrix[i] = malloc(sizeof(int) * cols);
        if(matrix[i] == NULL) {
            printf("Error allocating memory for matrix row\n");
            // Free any previously allocated rows
            for(int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return 1;
        }
    }

    /* Initialize the matrix with zeros */
    initializeMatrix(matrix, rows, cols, 0);
    
    /* Compute the sum of the matrix */
    int sum = calculateMatrixSum(matrix, rows, cols);
    if(sum == -1) {
        printf("Error calculating matrix sum\n");
        // Free allocated memory in case of calculation error
        for(int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
        return 1;
    }

    printf("Sum of matrix: %d\n", sum);

    // Clean up and free the allocated memory at the end
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    #-copilot next line-
}
```