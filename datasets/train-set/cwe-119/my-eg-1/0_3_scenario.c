```c
#include <stdio.h>
#include <string.h>

// Function to handle operations on given string based on command-line arguments
// The program will perform actions such as inserting or deleting a character
int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments are passed
    if (argc != 4) {
        printf("Usage: %s <string> <operation> <character>\n", argv[0]);
        return 1;
    }

    // Extract the string and operation character from arguments
    char *inputString = argv[1];
    char operation = argv[2][0];

    // Perform operation based on the user's selection
    switch (operation) {
        case 'i': {  // Insert a character at the beginning
            char newString[256];
            newString[0] = argv[3][0];
            strcpy(newString + 1, inputString);
            printf("String after insertion: %s\n", newString);
            break;
        }
        case 'd':   // Delete the first occurrence of a character
            char *pos = strchr(inputString, argv[3][0]);
            if (pos != NULL) {
                memmove(pos, pos + 1, strlen(pos));
                printf("String after deletion: %s\n", inputString);
            } else {
                printf("Character not found for deletion.\n");
            }
            break;
        default:
            printf("Unknown operation: %c\n", operation);
            return 1;
    }

    //-copilot next line-
}
```