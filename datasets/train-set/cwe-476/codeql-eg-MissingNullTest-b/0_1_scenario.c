```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int pages;  // New field added for the number of pages
    int year;   // Additional field for the publication year
} book;

int main() {
    // Allocate memory for a new book
    book *b = (book *)malloc(sizeof(book));
    if (b == NULL) {
        // Handle memory allocation failure
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }
    // Initialize the title and author, set the number of pages to 300, and year to 2020
    //-copilot next line-
}
```