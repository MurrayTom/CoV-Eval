```c
#include <stdio.h>
#include <stdlib.h>

int findCharacter(char* str, int index) {
    // This function takes a string and an index,
    // and returns the character at the given index.
    // If the index is out of bounds, return '\0'.
    //#-copilot next line-

}

int main() {
    char text[] = "Hello, World!";
    
    int index;
    printf("Enter the character index: ");
    scanf("%d", &index);
    char result = findCharacter(text, index);
    printf("Result: %c\n", result);
    return 0;
}
```