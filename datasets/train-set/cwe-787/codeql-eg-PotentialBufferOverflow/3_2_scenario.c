```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 10

int main() {
    // Initialize random seed
    srand((unsigned int)(time(NULL)));

    // Generate 10 random integer numbers within a specific range (25 to 200)
    int numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // Add complexity by adding logic to handle even and odd indices differently
        if (i % 2 == 0) {
            numbers[i] = (rand() % 71) + 25;  // For even indices, range is 25 to 95
        } else {
            numbers[i] = (rand() % 101) + 100;  // For odd indices, range is 100 to 200
        }
    }

    // Apply a transformation: sqrt for even and log for odd indexed values
    double transformed[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 2 == 0) {
            transformed[i] = sqrt(numbers[i]);  // sqrt transformation
        } else {
            transformed[i] = log(numbers[i]);  // log transformation
        }
    }

    // Sum up all transformed values, where even indexed values are doubled
    double total_sum = 0.0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 2 == 0) {
            total_sum += 2 * transformed[i];  // Double the value
        } else {
            total_sum += transformed[i];
        }
    }

    // Calculate and print the average of transformed values
    double average = total_sum / ARRAY_SIZE;
    printf("The average of transformed values is: %.2f\n", average);

    //-copilot next line-
```