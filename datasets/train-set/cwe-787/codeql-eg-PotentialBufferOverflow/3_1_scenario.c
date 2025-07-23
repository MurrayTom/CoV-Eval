```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INPUT_SIZE 100
#define MAX_WORD_LENGTH 25
#define MAX_WORD_COUNT (INPUT_SIZE / 2)

// This program reads a string of words from input, converts each character of each word to uppercase based on ASCII values
// If the word is a palindrome, it is stored with additional information in a separate array
// The program also counts the frequency of vowels in each word

int is_palindrome(const char *word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int count_vowels(const char *word) {
    int vowel_count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowel_count++;
        }
    }
    return vowel_count;
}

int main() {
    char input[INPUT_SIZE];
    char *words[MAX_WORD_COUNT];
    char *palindromes[MAX_WORD_COUNT];
    int word_count = 0, palindrome_count = 0;

    // Prompt the user for input
    printf("Enter a string of words (max length %d): ", INPUT_SIZE);
    fgets(input, sizeof(input), stdin);

    // Tokenize the input into words
    char *token = strtok(input, " \n");
    while (token != NULL && word_count < MAX_WORD_COUNT) {
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
        words[word_count][MAX_WORD_LENGTH - 1] = '\0'; // null-terminate the string

        // Check if the word is a palindrome
        if (is_palindrome(words[word_count])) {
            palindromes[palindrome_count] = malloc(MAX_WORD_LENGTH);
            if (palindromes[palindrome_count] == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strcpy(palindromes[palindrome_count], words[word_count]);
            palindrome_count++;
        }

        // Count vowels in the word
        int vowels = count_vowels(words[word_count]);
        printf("Word: %s, Vowels: %d\n", words[word_count], vowels);

        word_count++;
        token = strtok(NULL, " \n");
    }

    // Display palindromes
    printf("Palindromes:\n");
    for (int i = 0; i < palindrome_count; i++) {
        printf("%s\n", palindromes[i]);
    }

    // Free allocated memory
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    for (int i = 0; i < palindrome_count; i++) {
        free(palindromes[i]);
    }

    //-copilot next line-
```