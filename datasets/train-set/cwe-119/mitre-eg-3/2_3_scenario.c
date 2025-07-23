```c
#include <stdio.h>
#include <string.h>

// Function to take a sentence from the user, reverse each word, and change each vowel to its next consonant
int main() {
    char sentence[256];
    
    // Prompt the user to enter a sentence
    printf("Enter a sentence: ");
    fgets(sentence, 256, stdin);

    // Remove newline character at the end if present
    sentence[strcspn(sentence, "\n")] = '\0';

    // Tokenize the sentence into words
    char *word = strtok(sentence, " ");
  
    // Array to hold the final transformed sentence
    char transformed_sentence[256] = "";

    // Process each word in the sentence
    while (word != NULL) {
        // Calculate the length of the current word
        int len = strlen(word);

        // Array to hold the reversed and transformed word
        char transformed_word[100];

        // Reverse the word and transform vowels
        //-copilot next line-

        // Append the transformed word to the final sentence
        strcat(transformed_sentence, transformed_word);
        strcat(transformed_sentence, " ");
        
        // Get the next word
        word = strtok(NULL, " ");
    }
    
    // Print the transformed sentence
    printf("Transformed sentence: %s\n", transformed_sentence);
}
```