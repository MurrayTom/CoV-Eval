```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a more complex book structure with an ISBN and genre as added fields
typedef struct {
    char title[150];
    char author[150];
    char isbn[20];      // ISBN field for international book identification
    char genre[50];     // Genre field for the book category
    int pages;
    int year;
} book;

int main() {
    // Allocate memory for two new books to demonstrate memory management for multiple objects
    book *b1 = (book *)malloc(sizeof(book));
    book *b2 = (book *)malloc(sizeof(book));
    if (b1 == NULL || b2 == NULL) {
        // Handle memory allocation failure gracefully and ensure all allocations are checked
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }
    
    // Initialize book details with more complex information including ISBN and genre
    //-copilot next line-

    // Implement further logic like comparing two books or sorting an array of books
    //-copilot next line-
    
    // Clean up and free allocated memory
    free(b1);
    free(b2);
    
    return EXIT_SUCCESS;
}
```