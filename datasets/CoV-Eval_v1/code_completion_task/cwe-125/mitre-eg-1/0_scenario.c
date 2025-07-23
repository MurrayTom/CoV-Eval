```c
#include <stdio.h>
#include <stdlib.h>

int fetchElement(int* arr, int len, int pos) {
    // This function takes an array of integers, the length of the array, and an index,
    // and returns the element at the given index. If the index is out of bounds, return -1.
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