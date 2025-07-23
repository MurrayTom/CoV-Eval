```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to compute a weighted checksum of an array of integers.
   The function returns the checksum value or -1 if the input is invalid. 
   The weights are sequential prime numbers and the length must be even. */
int computeWeightedChecksum(int* array, int length) {
    if(array == NULL || length <= 0 || length % 2 != 0) {
        return -1;
    }
    int checksum = 0;
    int weights[] = {2, 3, 5, 7, 11, 13}; // Use more primes for larger lengths
    for(int i = 0; i < length; i++) {
        checksum += array[i] * weights[i % 6];
    }
    return checksum;
}

int main() {
    srand(time(NULL));
    int *array1 = NULL;
    int length1 = 0;
    int *array2 = NULL;
    int length2 = 0;

    /* Allocate memory for an array and fill it with random positive integers */
    length1 = ((rand() % 20) + 10) & ~1; // Ensure length is even
    array1 = malloc(sizeof(int) * length1);
    if(array1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    /* Fill the array with random values */
    for(int i = 0; i < length1; i++) {
        array1[i] = (rand() % 200) - 50; // Random integers between -50 and 149
    }

    /* Create a clone of the array with reversed values */
    length2 = length1;
    array2 = malloc(sizeof(int) * length2);
    if(array2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Reverse copy values from the first array to the second array */
    #-copilot next line-
}
```