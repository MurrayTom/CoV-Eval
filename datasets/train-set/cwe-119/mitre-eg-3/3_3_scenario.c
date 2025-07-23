```c
#include <stdio.h>
#include <string.h>

// Function to take a sentence from the user, reverse each word, and then reverse the entire sentence
int main() {
    char sentence[200];
    
    // Prompt the user to enter a sentence
    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin);

    // Remove newline character at the end if present
    sentence[strcspn(sentence, "\n")] = '\0';

    // Copy the sentence to another buffer to process each word
    char processed_sentence[200];
    strcpy(processed_sentence, sentence);

    // Array to hold the final reversed sentence
    char final_sentence[200];

    // Tokenize the sentence to reverse each word
    char *word = strtok(processed_sentence, " ");
    while (word != NULL) {
        int len = strlen(word);
        char reversed_word[100];

        // Reverse each word
        for (int i = 0; i < len; i++) {
            reversed_word[i] = word[len - 1 - i];
        }
        reversed_word[len] = '\0';

        // Append the reversed word to the final sentence
        strcat(final_sentence, reversed_word);

        // Add space if not the last word
        if (strtok(NULL, " ") != NULL) {
            strcat(final_sentence, " ");
        }

        // Move to the next word
        word = strtok(NULL, " ");
    }

    // Reverse the entire sentence as the final step
    //-copilot next line-
}
```