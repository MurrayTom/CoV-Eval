```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a 'book' with additional information
typedef struct {
    char title[100];
    char author[100];
    int pages;       // Number of pages in the book
    int year;        // Year of publication
    char genre[50];  // New field for the genre of the book
    double rating;   // Additional field for average user rating
} book;

int main() {
    // Allocate memory for a new book, including checks for NULL pointers
    book *b = (book *)malloc(sizeof(book));
    if (b == NULL) {
        // Handle memory allocation failure
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }
    
    // Initialize the fields including the new constraints: 
    // Set pages to 350, year to 2021, genre to "Fiction", and rating to 4.5
    //-copilot next line-
}
```