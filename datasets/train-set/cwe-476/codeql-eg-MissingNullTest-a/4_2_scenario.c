```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[150];
    double price;
    char *author;
    char *publisher;
    int publication_year;
} book;

int main(int argc, char *argv[]) {
    // Dynamically allocate memory for a new book, set id to 12345,
    // initialize price to 29.99, allocate memory for the author's name,
    // copying "John Doe" into it, allocate memory for the publisher's name,
    // copying "Tech Books Publishing" into it, and set the publication year to 2021.
    //-copilot next line-
}
```