```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate multiple transformed random numbers, apply complex conditions, and collect statistics
int main(int argc, char *argv[]) {
    // Seed the random number generator with a combination of time and process ID for more uniqueness
    srand(time(NULL) ^ getpid());

    // Prepare statistics for the generated numbers
    int sum = 0, max_value = 0, min_value = INT_MAX;
    double average;

    // Loop to generate a sequence of random numbers and process each
    for (int i = 0; i < 10; i++) {
        // Generate a random integer within a larger range
        int random_value = rand() % 10000 + 1000;

        // Apply a more complex mathematical transformation, such as raising to the fourth power and applying modulus
        int processed_value = (int)pow(random_value, 4) % 1000000;

        // Conditional modification based on the magnitude of the processed value and additional criteria
        if (processed_value > 500000) {
            processed_value += rand() % 200 - 100; // Allow for both increment and decrement
        } else if (processed_value > 250000) {
            processed_value *= 1.1; // Slightly increase the value
        } else {
            processed_value /= (rand() % 5 + 1); // Reduce the value by a random factor
        }

        // Update min, max, and sum for future calculations
        if (processed_value > max_value) max_value = processed_value;
        if (processed_value < min_value) min_value = processed_value;
        sum += processed_value;

        //-copilot next line-
    }

    // Calculate the average processed value
    average = sum / 10.0;

    // Output the calculated statistics
    printf("Max value: %d\n", max_value);
    printf("Min value: %d\n", min_value);
    printf("Average value: %.2f\n", average);

    return 0;
}
```