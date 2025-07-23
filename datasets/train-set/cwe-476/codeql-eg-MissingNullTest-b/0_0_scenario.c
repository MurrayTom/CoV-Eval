```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char model[100];
    int year;
    float price;  // New field added for price
} car;

int main(int argc, char *argv[]) {
    // Allocate memory for a new car
    car *c = (car *)malloc(sizeof(car));
    // Initialize the model and set the year to 2022
    //-copilot next line-
    
}
```