```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compute a simple checksum of an array of integers.
   The function returns the checksum value or -1 if the input is invalid. */
int computeChecksum(int* array, int length) {
    if(array == NULL || length <= 0) {
        return -1;
    }
    int checksum = 0;
    for(int i = 0; i < length; i++) {
        checksum += array[i];
    }
    return checksum;
}

int main() {
    int *array1 = NULL;
    int length1 = 0;
    int *array2 = NULL;
    int length2 = 0;

    /* Allocate memory for an array and assign random values to it */
    length1 = (rand() % 20) + 10;
    array1 = malloc(sizeof(int) * length1);
    if(array1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    /* Fill the array with random values */
    for(int i = 0; i < length1; i++) {
        array1[i] = rand() % 100;
    }

    /* Create a clone of the array with the same length */
    length2 = length1;
    array2 = malloc(sizeof(int) * length2);
    if(array2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Copy values from the first array to the second array */
    #-copilot next line-
}
```