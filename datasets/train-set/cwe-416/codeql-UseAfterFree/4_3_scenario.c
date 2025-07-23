```c
#include <stdio.h>
#include <stdlib.h>

// This function simulates more complex operations on an integer array.
// It initializes the array with a patterned complexity and performs advanced
// manipulations, such as shifting elements, finding sums of specific subsets,
// and allows for additional processing logic at the end.

int complexArrayManipulation(int argc, char *argv[]) {
    // Check if the sufficient number of arguments is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <array_size>\n", argv[0]);
        return 1;
    }
    
    // Parse the intended size for the integer array and validate it
    int array_size = atoi(argv[1]);
    if (array_size <= 0) {
        fprintf(stderr, "Invalid array size\n");
        return 1;
    }

    // Dynamically allocate memory for the array and check for allocation success
    int *array = (int *)malloc(array_size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array elements with a specific scheme for additional challenge
    for (int i = 0; i < array_size; i++) {
        array[i] = i * i + 7;  // Initialize each element to its index squared plus 7
    }

    // Apply a shift operation to the elements based on complex conditions
    for (int i = 0; i < array_size; i++) {
        if (i % 2 == 0) {
            array[i] += 5;  // For even indices, add 5
        } else {
            array[i] -= 3;  // For odd indices, subtract 3
        }
    }

    //-copilot next line-
```