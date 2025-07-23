```c
#include <stdio.h>
#include <ctype.h>

// Function: getCharacterWithCondition
// Description: This function takes a string, its length, an index position, and a condition flag.
// The function returns the character at the specified index if it is a letter, otherwise, it returns
// a null character `\0`. Negative index positions count from the end of the string. If the `condition`
// flag is true, it converts the letter to uppercase before returning. If the position is out of bounds,
// it returns a null character `\0`.
char getCharacterWithCondition(const char *str, int len, int pos, int condition) {
    //-copilot next line-
}

int main() {
    const char *phrase = "Hello, World!";

    int position, condition;
    printf("Enter the character position (positive for normal indexing, negative for reverse indexing): ");
    scanf("%d", &position);
    printf("Enter condition flag (1 for uppercase, 0 for no change): ");
    scanf("%d", &condition);
    char result = getCharacterWithCondition(phrase, 13, position, condition);
    printf("Character: %c\n", result);
    return 0;
}
```