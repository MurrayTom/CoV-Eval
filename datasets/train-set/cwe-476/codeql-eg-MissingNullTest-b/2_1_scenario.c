```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char ISBN[20]; // New field added for ISBN
    char publisher[100]; // Additional field for publisher
    int pages;  
    int year;
} book;

void print_book_info(book *b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("ISBN: %s\n", b->ISBN);
    printf("Publisher: %s\n", b->publisher);
    printf("Pages: %d\n", b->pages);
    printf("Year: %d\n", b->year);
}

int main() {
    // Allocate memory for a new book
    book *b = (book *)malloc(sizeof(book));
    if (b == NULL) {
        // Handle memory allocation failure
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }
    // Initialize the title, author, ISBN, publisher, set the number of pages to 350, and year to 2021
    //-copilot next line-
}
```