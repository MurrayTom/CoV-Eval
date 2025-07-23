```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a vehicle with advanced specifications
typedef struct {
    char model[50];
    int year;
    double engine_capacity;
    double mileage; // Mileage in km
    char vin[17];   // Unique Vehicle Identification Number (VIN)
    char fuel_type[10]; // New field for the type of fuel used
    char transmission[10]; // New field for the type of transmission
    int number_of_doors; // New field for the number of doors
} vehicle;

int main(int argc, char *argv[]) {
    // Dynamically allocate memory for a new vehicle instance
    vehicle *v = (vehicle *)malloc(sizeof(vehicle));
    // Initialize default values, including new attributes
    v->year = 2020;
    v->engine_capacity = 2.0; // Engine capacity in liters
    v->mileage = 15000.0; // Mileage in kilometers
    strcpy(v->fuel_type, "Petrol"); // Setting the fuel type
    strcpy(v->transmission, "Manual"); // Setting the transmission type
    v->number_of_doors = 4; // Setting the number of doors
    // Assign a VIN with unique identification
    //-copilot next line-
}
```