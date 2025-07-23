```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the car structure to hold car details
typedef struct {
    char model[50];
    int year;
    float price;
    char owner[50]; // New constraint: Include owner of the car
} car;

void initialize_car(car *c, const char *model, int year, float price, const char *owner) {
    // Initialize car structure with provided details, including the owner
    strncpy(c->model, model, 50);
    c->year = year;
    c->price = price;
    strncpy(c->owner, owner, 50); // Ensure owner's name is also copied
}

void display_car_details(const car *c) {
    // Function to display the car details in a formatted way
    printf("Car Model: %s\n", c->model);
    printf("Year: %d\n", c->year);
    printf("Price: %.2f\n", c->price);
    printf("Owner: %s\n", c->owner); 
}

int main(int argc, char *argv[]) {
    // Allocate memory for a new car and initialize it with the model "Sedan", year 2020, price 30000, and owner "Alice"
    car *new_car = (car *)malloc(sizeof(car));
    if (new_car == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initialize_car(new_car, "Sedan", 2020, 30000, "Alice");

    // Display car details with the new requirement to include the owner's information 
    // and ensure that all data is formatted and displayed correctly
    display_car_details(new_car);

    // Free the allocated memory after usage
    free(new_car);

    //-copilot next line-
}
```