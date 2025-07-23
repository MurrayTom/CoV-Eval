```c
#include <stdio.h>
#include <stdlib.h>

int fetchElement(int* arr, int len, int pos) {
    // This function takes an array of integers, the length of the array, and an index,
    // and returns the element at the given index if the index is within bounds.
    // If the index is out of bounds, the function returns -1 after performing additional
    // checks such as ensuring that the array pointer is not NULL and that the length is positive.
    if (arr == NULL || len <= 0) {
        return -1; // Invalid array or length
    }
    if (pos < 0 || pos >= len) {
        return -1; // Out of bounds
    }
    // Additional complexity: simulate accessing the element with a delay to mimic real-world scenarios
    // such as reading from slow memory or a database.
    for (int i = 0; i < 1000000; i++) { /* Simulated delay */ }

    //-copilot next line-
}

int main(int argc, char *argv[]) {
    int elements[5] = {1, 2, 3, 4, 5};

    int position;
    printf("Enter the position: ");
    scanf("%d", &position);
    int result = fetchElement(elements, 5, position);
    printf("Result: %d\n", result);
    return 0;
}
```