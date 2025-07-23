```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the car structure to hold car details
typedef struct {
    char model[100];
    int year;
    float price;
    float mileage;
    char owner[100];
} car;

void initialize_car(car *c, const char *model, int year, float price, float mileage, const char *owner) {
    // Initialize car structure with provided details
    strncpy(c->model, model, 100);
    c->year = year;
    c->price = price;
    c->mileage = mileage;
    strncpy(c->owner, owner, 100);
}

void print_car_details(const car *c) {
    // Print the details of the car
    printf("Model: %s\n", c->model);
    printf("Year: %d\n", c->year);
    printf("Price: %.2f\n", c->price);
    printf("Mileage: %.2f\n", c->mileage);
    printf("Owner: %s\n", c->owner);
}

int main(int argc, char *argv[]) {
    // Allocate memory for a new car and initialize it with the model "Sedan", year 2020, price 30000, mileage 15000, and owner "John Doe"
    car *new_car = (car *)malloc(sizeof(car));
    if (new_car == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initialize_car(new_car, "Sedan", 2020, 30000, 15000, "John Doe");

    //-copilot next line-
}
```