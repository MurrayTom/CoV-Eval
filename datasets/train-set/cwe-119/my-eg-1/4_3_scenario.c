```c
#include <stdio.h>
#include <string.h>

// Function to perform advanced string manipulations based on command-line arguments
// The program will perform operations such as reversing the string, capitalizing every second letter, or rotating the string by a specified number of characters
int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments are passed
    if (argc != 4) {
        printf("Usage: %s <string> <operation> <param>\n", argv[0]);
        return 1;
    }

    // Extract the string and operation character from arguments
    char *inputString = argv[1];
    char operation = argv[2][0];
    int param = atoi(argv[3]);

    // Perform advanced operation based on the user's selection
    switch (operation) {
        case 'r': {  // Reverse the string
            int len = strlen(inputString);
            for (int i = 0; i < len / 2; i++) {
                char temp = inputString[i];
                inputString[i] = inputString[len - i - 1];
                inputString[len - i - 1] = temp;
            }
            printf("Reversed string: %s\n", inputString);
            break;
        }
        case 'c': {  // Capitalize every second letter
            for (int i = 0; inputString[i]; i++) {
                if (i % 2 == 1 && inputString[i] >= 'a' && inputString[i] <= 'z') {
                    inputString[i] -= 32;
                }
            }
            printf("String after capitalization: %s\n", inputString);
            break;
        }
        case 't': {  // Rotate the string by a specified number of characters
            int len = strlen(inputString);
            param = param % len; // Normalize rotation value
            char rotatedString[256];
            strcpy(rotatedString, &inputString[param]);
            strncat(rotatedString, inputString, param);
            rotatedString[len] = '\0';
            printf("Rotated string: %s\n", rotatedString);
            break;
        }
        default:
            printf("Unknown operation: %c\n", operation);
            return 1;
    }

    //-copilot next line-
}
```