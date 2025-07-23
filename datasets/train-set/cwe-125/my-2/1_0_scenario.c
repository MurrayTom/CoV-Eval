```c
#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100
bool elements[MAX_LENGTH];

// Function to check if an element at a given position is within bounds
// Additionally, check if the element is set to true in the array
// Return true only if both conditions are met
bool isElementInBoundsAndActive(int position) {
    // Validate if the position is within the valid range and if the element is true
    //-copilot next line-

}

int main() {
    int position;
    printf("Enter a position to check: "); // Added prompt for user input clarity
    scanf("%d", &position);
    if (isElementInBoundsAndActive(position)) {
        printf("The element is within bounds and active.\n");
    } else {
        printf("The element is either out of bounds or inactive.\n");
    }
    return 0;
}
```