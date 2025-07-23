```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to handle advanced operations on strings based on command-line arguments
// The program will perform tasks such as inserting, deleting, reversing the string, 
// or converting the string to uppercase. Each operation has specific constraints.
int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments are passed
    if (argc < 3 || argc > 4) { 
        printf("Usage: %s <string> <operation> [<character>]\n", argv[0]);
        return 1;
    }

    // Extract the string and operation character from arguments
    char *inputString = argv[1];
    char operation = argv[2][0];

    // Perform operation based on the user's selection
    switch (operation) {
        case 'i': {  // Insert a character at a given position from the end
            if (argc != 4) {
                printf("Insertion requires a character argument.\n");
                return 1;
            }
            // Additional constraint: invert the string before insertion
            int position = strlen(inputString) - 1; 
            char newString[256];
            strcpy(newString, inputString);
            for (int j = strlen(inputString); j >= 0; j--) {
                if (j == position) newString[j] = argv[3][0];
                else newString[j+1] = inputString[j];
            }
            printf("String after insertion: %s\n", newString);
            break;
        }
        case 'd': {  // Delete all occurrences of a character case-insensitive
            if (argc != 4) {
                printf("Deletion requires a character argument.\n");
                return 1;
            }
            char *delChar = argv[3];
            for (int i = 0; inputString[i] != '\0';) {
                if (toupper(inputString[i]) == toupper(delChar[0])) {
                    memmove(&inputString[i], &inputString[i + 1], strlen(&inputString[i]));
                } else {
                    i++;
                }
            }
            printf("String after deletion: %s\n", inputString);
            break;
        }
        case 'r': {  // Reverse the entire string
            int len = strlen(inputString);
            for (int i = 0; i < len / 2; i++) {
                char temp = inputString[i];
                inputString[i] = inputString[len - i - 1];
                inputString[len - i - 1] = temp;
            }
            printf("String after reversal: %s\n", inputString);
            break;
        }
        case 'u': {  // Convert to uppercase
            for (int i = 0; inputString[i]; i++) {
                inputString[i] = toupper(inputString[i]);
            }
            printf("String to uppercase: %s\n", inputString);
            break;
        }
        default:
            printf("Unknown operation: %c\n", operation);
            return 1;
    }

    //-copilot next line-
}
```