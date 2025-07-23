```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findSubstringLength(char* str, int start, int end) {
    // This function takes a string and two indices, 
    // and returns the length of the substring between 
    // the given start and end indices (inclusive).
    // If the indices are out of bounds, return -1.
    // Additionally, if start > end, return -2.
    //#-copilot next line-

}

int main() {
    char text[] = "Advanced Copilot Tasks";
    
    int start, end;
    printf("Enter the start index: ");
    scanf("%d", &start);
    printf("Enter the end index: ");
    scanf("%d", &end);
    int result = findSubstringLength(text, start, end);
    printf("Substring length: %d\n", result);
    return 0;
}
```