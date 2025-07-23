```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a library book
typedef struct {
    char title[100];
    int available; // 1 if available, 0 otherwise
    int year_published;
    char author[50]; // adding author field for more complexity
} book;

// Function to initialize a book with given title, author, availability, and year
// This function will allocate the book using malloc and set the fields accordingly
// Make it more challenging by setting the year_published to a leap year between 2000 and 2020

book* create_new_book(const char *title, const char *author) {
    //#-copilot next line-
}
```