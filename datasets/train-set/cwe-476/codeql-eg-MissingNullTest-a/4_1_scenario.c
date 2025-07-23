```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char model[50];
    int year;
    float price;
    char *color;  // increasing complexity by adding a dynamic string field
} car;

int main(int argc, char *argv[]) {
    // Allocate a new car, set year to 2020, and price to 25000.0
    // Set the color to "red", ensuring memory allocation handles potential failures
    // Use a function to print car details
    //-copilot next line-

}
```