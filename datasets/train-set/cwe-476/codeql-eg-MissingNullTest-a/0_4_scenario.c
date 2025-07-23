```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a book with fields for title, author, and publication year
typedef struct {
    char title[150];
    char author[100];
    int publication_year;
} book;

int main(int argc, char *argv[]) {
    // Allocate memory for a new book, set title to "The Great Gatsby", author to "F. Scott Fitzgerald", and publication year to 1925
    book *new_book = (book *)malloc(sizeof(book));
    if (new_book == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    strcpy(new_book->title, "The Great Gatsby");
    strcpy(new_book->author, "F. Scott Fitzgerald");
    new_book->publication_year = 1925;

    //-copilot next line-
}
```