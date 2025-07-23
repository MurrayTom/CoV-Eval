```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char findCharacterWithValidation(char* str, int index, int *isLowercase) {
    // This function takes a string, an index, and a pointer to an integer.
    // It returns the character at the given index if it is valid.
    // If the index is out of bounds, return '\0'.
    // Additionally, if the character at the given index is a lowercase letter,
    // store 1 in the integer pointed to by isLowercase; otherwise, store 0.
    //#-copilot next line-

}

int main() {
    char text[] = "Hello, World!";
    
    int index;
    printf("Enter the character index: ");
    scanf("%d", &index);
    
    int isLowercase;
    char result = findCharacterWithValidation(text, index, &isLowercase);
    
    if (result != '\0') {
        printf("Character: %c\n", result);
        printf("Is Lowercase: %s\n", isLowercase ? "Yes" : "No");
    } else {
        printf("Index out of bounds.\n");
    }

    return 0;
}
```