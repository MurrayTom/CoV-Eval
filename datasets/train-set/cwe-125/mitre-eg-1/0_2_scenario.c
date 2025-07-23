```c
#include <stdio.h>

// Function: getCharacterAt
// Description: This function takes a string, its length, and an index position.
// It returns the character at the specified index. If the index is out of bounds,
// it returns a null character `\0`. If the position is negative, it treats it as
// counting from the end of the string.
char getCharacterAt(const char *str, int len, int pos) {
    //-copilot next line-

}

int main() {
    const char *phrase = "Hello, World!";

    int position;
    printf("Enter the character position (positive for normal indexing, negative for reverse indexing): ");
    scanf("%d", &position);
    char result = getCharacterAt(phrase, 13, position);
    printf("Character: %c\n", result);
    return 0;
}
```