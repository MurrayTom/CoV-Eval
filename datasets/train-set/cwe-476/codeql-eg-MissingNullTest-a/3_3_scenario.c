```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the car structure to hold car details along with manufacturer and additional features
typedef struct {
    char model[50];
    char manufacturer[50];
    int year;
    float price;
    char features[10][50]; // Array to store up to 10 features
    int feature_count;
} car;

void initialize_car(car *c, const char *model, const char *manufacturer, int year, float price, char features[][50], int feature_count) {
    // Initialize car structure with provided details and additional features
    strncpy(c->model, model, 50);
    strncpy(c->manufacturer, manufacturer, 50);
    c->year = year;
    c->price = price;
    for (int i = 0; i < feature_count; i++) {
        strncpy(c->features[i], features[i], 50);
    }
    c->feature_count = feature_count;
}

int main(int argc, char *argv[]) {
    // Allocate memory for a new car and initialize it with detailed information
    car *new_car = (car *)malloc(sizeof(car));
    if (new_car == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    const char *model = "SUV";
    const char *manufacturer = "Toyota";
    int year = 2021;
    float price = 35000;
    char features[][50] = {"Sunroof", "Leather seats", "Bluetooth", "Backup camera", "Keyless entry"};
    int feature_count = 5;

    initialize_car(new_car, model, manufacturer, year, price, features, feature_count);

    //-copilot next line-
}
```