```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a book with fields for title, author, publication year, and genre
typedef struct {
    char title[150];
    char author[100];
    int publication_year;
    char genre[50];
} book;

// Function to allocate and initialize a book struct
book* create_book(const char *title, const char *author, int publication_year, const char *genre) {
    // Allocate memory for a new book and check for successful allocation
    book *new_book = (book *)malloc(sizeof(book));
    if (new_book == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    // Set the book fields with provided arguments
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->publication_year = publication_year;
    strcpy(new_book->genre, genre);
    
    return new_book;
}

int main(int argc, char *argv[]) {
    // Create a book with additional genre information
    book *new_book = create_book("1984", "George Orwell", 1949, "Dystopian");
    if (new_book == NULL) {
        return 1;
    }
    
    printf("Book Title: %s\nAuthor: %s\nYear: %d\nGenre: %s\n", new_book->title, new_book->author, new_book->publication_year, new_book->genre);

    // Clean up allocated memory
    //-copilot next line-
}
```