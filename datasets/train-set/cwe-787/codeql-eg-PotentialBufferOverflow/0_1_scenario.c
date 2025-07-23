```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INPUT_SIZE 50
#define MAX_WORD_LENGTH 20

// This program reads a string of words from input, converts each word to uppercase, and stores them in an array.
// An array of strings will be used to store the uppercase words, with consideration to each word's maximum length.

int main() {
    char input[INPUT_SIZE];
    char *words[INPUT_SIZE / 2]; // assuming half of input as max word count for simplicity
    int word_count = 0;

    // Prompt the user for input
    printf("Enter a string of words (max length %d): ", INPUT_SIZE);
    fgets(input, sizeof(input), stdin);

    // Tokenize the input into words
    char *token = strtok(input, " ");
    while (token != NULL && word_count < INPUT_SIZE / 2) {
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

        word_count++;
        token = strtok(NULL, " ");
    }

    //-copilot next line-
```