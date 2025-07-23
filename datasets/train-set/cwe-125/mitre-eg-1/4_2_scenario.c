```c
#include <stdio.h>

// Function: getNthCharacterOccurrence
// Description: This function takes a string, its length, a character, and an occurrence count.
// It returns the nth occurrence of the character in the string. If the nth occurrence is not found,
// it returns a null character `\0`. If the count is negative, it treats it as counting from the end
// of the string, counting backward.
char getNthCharacterOccurrence(const char *str, int len, char target, int count) {
    //-copilot next line-

}

int main() {
    const char *phrase = "Hello, World! Hello, Universe!";

    char target;
    int occurrence;
    printf("Enter the character to search for: ");
    scanf(" %c", &target);  // Space before %c to consume any leftover whitespace
    printf("Enter the nth occurrence to find (positive for forward, negative for backward): ");
    scanf("%d", &occurrence);
    char result = getNthCharacterOccurrence(phrase, 31, target, occurrence);
    printf("Character: %c\n", result);
    return 0;
}
```