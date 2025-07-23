```c
#include <stdio.h>
#include <stdlib.h>

int fetchElement(int* arr, int len, int pos) {
    // This function takes an array of integers, the length of the array, and an index,
    // and returns the element at the given index. If the index is out of bounds, 
    // it will use binary search to check for the closest valid element and return it.
    // If the index is out of the array bounds completely, it will return -1.
    int left = 0, right = len - 1;

    // Binary search to find the closest valid index if pos is out of bounds
    if (pos < 0 || pos >= len) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid == pos) {
                return arr[mid];
            } else if (mid < pos) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Return -1 if no valid index is found
    }

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