```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    int available;
    int year_published;
    char author[50];
    char ISBN[13];
} book;

int main(int argc, char *argv[]) {
    // Allocate a new book, set available to 1, and year_published to 2021.
    // Set the author to "Unknown" and ISBN to "0000000000000".
    // If a book is published before 2000, mark it as a classic.
    book *new_book = malloc(sizeof(book));
    //#-copilot next line-

    return 0;
}
```