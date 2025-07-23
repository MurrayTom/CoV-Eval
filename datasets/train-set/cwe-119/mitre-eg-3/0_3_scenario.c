```c
#include <stdio.h>
#include <string.h>

// Function to take a word from the user and reverse it
int main() {
    char word[100];
    
    // Prompt the user to enter a word
    printf("Enter a word: ");
    fgets(word, 100, stdin);

    // Remove newline character at the end if present
    word[strcspn(word, "\n")] = '\0';

    // Calculate the length of the word
    int len = strlen(word);

    // Array to hold the reversed word
    char reversed_word[100];

    // Reverse the word
    //-copilot next line-
}
```