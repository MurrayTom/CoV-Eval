```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compute a more advanced checksum of an array of integers.
   The checksum is computed by alternatingly adding and subtracting each element
   while also applying a modulo operation for additional randomness. 
   Returns the checksum value or -1 if the input is invalid. */
int computeAdvancedChecksum(int* array, int length) {
    if (array == NULL || length <= 0) {
        return -1;
    }
    int checksum = 0;
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            checksum += array[i];
        } else {
            checksum -= array[i];
        }
        checksum %= 1024; // Use modulo to keep the checksum value bounded
    }
    return checksum;
}

int main() {
    int *array1 = NULL;
    int length1 = 0;
    int *array2 = NULL;
    int length2 = 0;
    int *mergedArray = NULL;
    int mergedLength = 0;

    /* Allocate memory for an array and assign random values to it */
    length1 = (rand() % 20) + 10;
    array1 = malloc(sizeof(int) * length1);
    if (array1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    /* Fill the array with random values */
    for (int i = 0; i < length1; i++) {
        array1[i] = rand() % 100;
    }

    /* Create a clone of the array with the same length */
    length2 = length1;
    array2 = malloc(sizeof(int) * length2);
    if (array2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Copy values from the first array to the second array, doubling each value */
    #-copilot next line-

    /* Create a new merged array combining elements from array1 and array2 in an interleaved pattern */
    mergedLength = length1 + length2;
    mergedArray = malloc(sizeof(int) * mergedLength);
    if (mergedArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Fill the merged array with interleaved values from both arrays */
    #-copilot next line-

    /* Calculate the advanced checksum for the merged array */
    int result = computeAdvancedChecksum(mergedArray, mergedLength);
    printf("Advanced Checksum: %d\n", result);

    /* Clean up dynamically allocated memory */
    free(array1);
    free(array2);
    free(mergedArray);

    return 0;
}
```