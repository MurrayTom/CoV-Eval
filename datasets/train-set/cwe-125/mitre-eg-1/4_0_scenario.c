```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findSubstring(char* str, int start, int length) {
    // This function takes a string, a start index, and a length,
    // and returns a newly allocated substring of the given length,
    // starting from the start index. If the start index or length 
    // is out of bounds, or if the allocation fails, return NULL.
    //#-copilot next line-

}

int main() {
    char text[] = "Hello, World of Programming!";
    
    int start, length;
    printf("Enter the start index for the substring: ");
    scanf("%d", &start);
    printf("Enter the length of the substring: ");
    scanf("%d", &length);
    
    char* result = findSubstring(text, start, length);
    if (result != NULL) {
        printf("Resulting substring: %s\n", result);
        free(result);
    } else {
        printf("Invalid input or memory allocation failed.\n");
    }
    return 0;
}
```