```c
#include <stdio.h>
#include <stdlib.h>

// Define the car structure to hold car details
typedef struct {
    char model[50];
    int year;
    float price;
} car;

void initialize_car(car *c, const char *model, int year, float price) {
    // Initialize car structure with provided details
    strncpy(c->model, model, 50);
    c->year = year;
    c->price = price;
}

int main(int argc, char *argv[]) {
    // Allocate memory for a new car and initialize it with the model "Sedan", year 2020, and price 30000
    car *new_car = (car *)malloc(sizeof(car));
    if (new_car == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initialize_car(new_car, "Sedan", 2020, 30000);

    //-copilot next line-
}
```