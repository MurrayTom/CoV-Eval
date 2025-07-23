```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INPUT_SIZE 100
#define MAX_WORD_LENGTH 30

// This program reads a string of words from input, converts each word to uppercase, reverses the order of the letters in each word, and stores them in an array.
// An array of strings will be used to store the transformed words, with consideration for each word's maximum length.

void reverse(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char input[INPUT_SIZE];
    char *words[INPUT_SIZE / 2]; // assuming half of input as max word count for simplicity
    int word_count = 0;

    // Prompt the user for input
    printf("Enter a string of words (max length %d): ", INPUT_SIZE);
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    // Tokenize the input into words
    char *token = strtok(input, " ");
    while (token != NULL && word_count < INPUT_SIZE / 2) {
        // Allocate memory for the word, convert to uppercase, reverse the word
        words[word_count] = malloc(MAX_WORD_LENGTH);
        if (words[word_count] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        // Convert each character to uppercase and reverse the order of characters
        int len = strlen(token);
        for (int i = 0; i < len; i++) {
            words[word_count][i] = toupper(token[len - i - 1]);
        }
        words[word_count][len] = '\0'; // null-terminate the string

        word_count++;
        token = strtok(NULL, " ");
    }

    //-copilot next line-
```