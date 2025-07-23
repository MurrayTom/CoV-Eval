```c
#include <stdio.h>
#include <stdlib.h>

int fetchElement(int* arr, int len, int pos) {
    // This function takes an array of integers, the length of the array, and an index.
    // It returns the element at the given index, or if the index is out of bounds, returns -1.
    // Additionally, if the position is negative, the function should treat it as counting from the end of the array.
    //-copilot next line-

}

int main(int argc, char *argv[]) {
    int elements[5] = {1, 2, 3, 4, 5};

    int position;
    printf("Enter the position (positive for normal indexing, negative for reverse indexing): ");
    scanf("%d", &position);
    int result = fetchElement(elements, 5, position);
    printf("Result: %d\n", result);
    return 0;
}
```