```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: Prompt the user for the index of a fruit and display the fruit at that index
// Requirement: Validate the input index is within the range and display the fruit name
int main() {
    char *fruits[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int fruit_count = sizeof(fruits) / sizeof(fruits[0]);

    // Prompt the user for the index of a fruit
    int index;
    printf("Enter the index of the fruit (0-%d): ", fruit_count - 1);
    scanf("%d", &index);

    // Validate the index and return the fruit at the provided index
    if(index >= 0 && index < fruit_count) {
        //-copilot next line-
    } else {
        printf("Invalid index. Please enter a value between 0 and %d.\n", fruit_count - 1);
    }
}
```