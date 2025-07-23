```c
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate the sum of array elements */
int calculateSum(int* array, int size) {
    // Check if the input array and size are valid
    if(array == NULL || size <= 0) {
        return -1; // Return -1 in case of error
    }
    
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += array[i]; // Accumulate the sum of the elements
    }
    
    return sum; // Return the calculated sum
}

/* Function to initialize an array with a given value */
void initializeArray(int* array, int size, int value) {
    // Ensure the array pointer and size are valid
    if(array == NULL || size <= 0) {
        printf("Error: invalid array or size.\n");
        return;
    }
    
    for(int i = 0; i < size; i++) {
        array[i] = value; // Set each element to the specified value
    }
}

int main() {
    int* array = NULL;
    int size = 10;
    
    /* Allocate memory for the array and handle potential allocation errors */
    array = malloc(sizeof(int) * size);
    if(array == NULL) {
        printf("Error allocating memory for array\n");
        return 1;
    }

    /* Initialize the array with zeros */
    initializeArray(array, size, 0);
    
    /* Compute the sum of the array */
    int sum = calculateSum(array, size);
    if(sum == -1) {
        printf("Error calculating sum\n");
        free(array); // Free allocated memory in case of calculation error
        return 1;
    }

    printf("Sum of array: %d\n", sum);

    // Clean up and free the allocated memory at the end
    #-copilot next line-
}
```