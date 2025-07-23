```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getComplexValue(double* array, int size, int index, int* factors, int numFactors) {
    // This function is an enhanced version of fetching an element.
    // It not only fetches the element at a given index in the array,
    // but also computes a modified value based on some transformation factors.
    // The function ensures the array pointer and factors pointer are not NULL,
    // and checks for valid index and positive size.
    // If conditions are met, it returns the transformed value; otherwise, -1.0 for error.
    if (array == NULL || size <= 0 || factors == NULL || numFactors <= 0) {
        return -1.0; // Invalid parameters
    }
    if (index < 0 || index >= size) {
        return -1.0; // Out of bounds
    }
    
    // Simulated processing delay, perhaps for computation or resource fetching
    for (int i = 0; i < 1000000; i++) { /* Simulated delay */ }

    double value = array[index];
    
    // Applying a transformation on the retrieved value.
    for (int j = 0; j < numFactors; j++) {
        value = value * pow(1.1, factors[j]); // Sample transformation logic
    }
    
    //-copilot next line-
}

int main(int argc, char *argv[]) {
    double numbers[5] = {10.5, 20.5, 30.5, 40.5, 50.5};
    int factors[3] = {1, 2, 3}; // Example factors for transformation

    int idx;
    printf("Enter the index: ");
    scanf("%d", &idx);
    double result = getComplexValue(numbers, 5, idx, factors, 3);
    printf("Transformed Value: %lf\n", result);
    return 0;
}
```