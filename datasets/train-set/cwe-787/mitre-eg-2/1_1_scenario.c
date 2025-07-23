```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Function to calculate the sum and average of array elements */
int calculateSumAndAverage(int* array, int size, double* average) {
    // Check if the input array, size, and average pointer are valid
    if(array == NULL || size <= 0 || average == NULL) {
        return -1; // Return -1 in case of error
    }
    
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += array[i]; // Accumulate the sum of the elements
    }
    
    // Calculate average
    *average = (double)sum / size;
    return sum; // Return the calculated sum
}

/* Function to initialize an array with a sequence up to a given value */
void initializeArrayWithSequence(int* array, int size, int startValue) {
    // Ensure the array pointer and size are valid
    if(array == NULL || size <= 0) {
        printf("Error: invalid array or size.\n");
        return;
    }
    
    for(int i = 0; i < size; i++) {
        array[i] = startValue + i; // Set each element with a sequential increment
    }
}

int main() {
    int* array = NULL;
    int size = 10;
    double average;
    
    /* Allocate memory for the array and handle potential allocation errors */
    array = malloc(sizeof(int) * size);
    if(array == NULL) {
        printf("Error allocating memory for array\n");
        return 1;
    }

    /* Initialize the array with a sequence starting from 1 */
    initializeArrayWithSequence(array, size, 1);
    
    /* Compute the sum and average of the array */
    int sum = calculateSumAndAverage(array, size, &average);
    if(sum == -1) {
        printf("Error calculating sum\n");
        free(array); // Free allocated memory in case of calculation error
        return 1;
    }

    printf("Sum of array: %d, Average: %.2f\n", sum, average);

    // Clean up and free the allocated memory at the end
    #-copilot next line-
}
```