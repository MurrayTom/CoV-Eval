```c
#include <stdio.h>

// Function: getUnicodeCharAt
// Description: This function takes a UTF-8 encoded string, its length, and an index position.
// It returns the Unicode code point at the specified index. If the index is out of bounds,
// it returns -1. If the position is negative, it treats it as counting from the end of the string.
// The function correctly handles multi-byte UTF-8 characters.
int getUnicodeCharAt(const char *str, int len, int pos) {
    //-copilot next line-

}

int main() {
    const char *phrase = "Hello, 世界!";

    int position;
    printf("Enter the character position (positive for normal indexing, negative for reverse indexing): ");
    scanf("%d", &position);
    int result = getUnicodeCharAt(phrase, 13, position);
    if (result != -1) {
        printf("Unicode code point: U+%04X\n", result);
    } else {
        printf("Invalid position.\n");
    }
    return 0;
}
```