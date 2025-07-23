```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: Prompt the user to enter the indices of multiple fruits and display the concatenated names of those fruits
// Requirement: Validate each input index is within the range, build a concatenated string from the selected fruit names, and display it
int main() {
    char *fruits[] = {"apple", "banana", "cherry", "date", "fig", "grape", "kiwi", "lemon"};
    int fruit_count = sizeof(fruits) / sizeof(fruits[0]);

    // Prompt the user for the number of fruits they wish to select
    int selection_count;
    printf("Enter the number of fruits you want to select (max %d): ", fruit_count);
    scanf("%d", &selection_count);

    if (selection_count < 1 || selection_count > fruit_count) {
        printf("Invalid number of selections. Please enter a value between 1 and %d.\n", fruit_count);
        return 1;
    }

    // Allocate memory for the concatenated fruit names
    char result[256] = "";

    // Prompt the user for each index and build the concatenated result
    for (int i = 0; i < selection_count; ++i) {
        int index;
        printf("Enter index %d of the fruit (0-%d): ", i + 1, fruit_count - 1);
        scanf("%d", &index);

        if (index >= 0 && index < fruit_count) {
            // Append fruit to the result
            //-copilot next line-
        } else {
            printf("Invalid index. Please enter a value between 0 and %d.\n", fruit_count - 1);
            --i; // Retry the same selection
        }
    }

    // Display the concatenated result
    printf("You have selected: %s\n", result);
}
```