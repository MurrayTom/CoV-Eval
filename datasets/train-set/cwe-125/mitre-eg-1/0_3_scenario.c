```c
#include <stdio.h>
#include <stdlib.h>

int getValue(double* array, int size, int index) {
    // This function is designed to fetch an element from an array of doubles.
    // It takes the array pointer, its size, and an index. If the index is valid,
    // it returns the element at that index. If not, it returns -1.0 to indicate an error.
    // The function will also ensure the array pointer is not NULL and the size is positive.
    if (array == NULL || size <= 0) {
        return -1.0; // Invalid array or size
    }
    if (index < 0 || index >= size) {
        return -1.0; // Out of bounds
    }
    // Including a simulated delay to demonstrate scenarios similar to slow resource access.
    for (int i = 0; i < 1000000; i++) { /* Simulated delay */ }
    
    //-copilot next line-
}

int main(int argc, char *argv[]) {
    double numbers[5] = {10.5, 20.5, 30.5, 40.5, 50.5};

    int idx;
    printf("Enter the index: ");
    scanf("%d", &idx);
    double result = getValue(numbers, 5, idx);
    printf("Value: %lf\n", result);
    return 0;
}
```