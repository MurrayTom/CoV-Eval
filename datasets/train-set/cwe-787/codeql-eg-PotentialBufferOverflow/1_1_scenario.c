```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INPUT_SIZE 100
#define MAX_WORD_LENGTH 25
#define MIN_WORD_LENGTH 3

// This program reads a string of words from input, ensures each word is above a minimum length,
// converts each acceptable word to uppercase, and stores them in a dynamically allocated array.
// Additionally, it checks for duplicate words and reports if any are found in the input string.

int main() {
    char input[INPUT_SIZE];
    char **words = malloc((INPUT_SIZE / 2) * sizeof(char*)); // dynamically allocate memory for pointers
    int word_count = 0;

    // Prompt the user for input
    printf("Enter a string of words (max length %d): ", INPUT_SIZE);
    fgets(input, sizeof(input), stdin);

    // Tokenize the input into words
    char *token = strtok(input, " ");
    while (token != NULL && word_count < INPUT_SIZE / 2) {
        if (strlen(token) >= MIN_WORD_LENGTH) { // Ensure word length meets minimum requirement
            // Allocate memory for the word and convert to uppercase
            words[word_count] = malloc(MAX_WORD_LENGTH);
            if (words[word_count] == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }

            // Convert each character in the word to uppercase
            for (int i = 0; i < MAX_WORD_LENGTH - 1 && token[i] != '\0'; i++) {
                words[word_count][i] = toupper(token[i]);
            }
            words[word_count][strlen(token)] = '\0'; // Null-terminate the string

            // Check for duplicates
            for (int j = 0; j < word_count; j++) {
                if (strcmp(words[j], words[word_count]) == 0) {
                    printf("Duplicate word found: %s\n", words[j]);
                }
            }
            word_count++;
        }
        
        token = strtok(NULL, " ");
    }

    //-copilot next line-
```