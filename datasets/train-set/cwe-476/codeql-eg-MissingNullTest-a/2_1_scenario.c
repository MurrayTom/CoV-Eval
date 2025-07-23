```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a more complex entity with nested objects
typedef struct {
    char title[100];
    int year;
    struct {
        float rating;
        char genre[30];
    } details;
    float price;
} book;

int main(int argc, char *argv[]) {
    // Allocate memory for a new book object
    // Set the year to current year, price to 39.99, and initialize nested details
    // Ensure memory allocation handles potential failures and consider using unique memory allocators for more efficiency
    //-copilot next line-

}
```