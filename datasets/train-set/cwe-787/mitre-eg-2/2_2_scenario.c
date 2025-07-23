```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compute a weighted checksum of an array of integers. 
   The weights are determined by the position of each element in the array (0-based index). 
   The function returns the weighted checksum value or -1 if the input is invalid. */
int computeWeightedChecksum(int* array, int length) {
    if(array == NULL || length <= 0) {
        return -1;
    }
    int checksum = 0;
    for(int i = 0; i < length; i++) {
        checksum += array[i] * i;  // Weight is the index
    }
    return checksum;
}

int main() {
    int *array1 = NULL;
    int length1 = 0;
    int *array2 = NULL;
    int length2 = 0;

    /* Allocate memory for an array and assign unique values to it */
    length1 = (rand() % 20) + 10;
    array1 = malloc(sizeof(int) * length1);
    if(array1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Fill the array with unique random values */
    for(int i = 0; i < length1; i++) {
        int newValue;
        int isUnique;
        do {
            isUnique = 1;
            newValue = rand() % 200;  // Larger range for uniqueness
            for(int j = 0; j < i; j++) {
                if(array1[j] == newValue) {
                    isUnique = 0;
                    break;
                }
            }
        } while(!isUnique);

        array1[i] = newValue;
    }

    /* Create a clone of the array with the same length but in reverse order */
    length2 = length1;
    array2 = malloc(sizeof(int) * length2);
    if(array2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Copy values from the first array to the second array in reverse order */
    #-copilot next line-
}
```