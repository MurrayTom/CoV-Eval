```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate multiple random numbers, apply complex transformations, and output results based on additional conditions
int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Generate multiple random integers within a specified range larger than 1000
    int numbers[5];
    for (int i = 0; i < 5; i++) {
        numbers[i] = rand() % 2000 + 1001;
    }

    // Define an array to hold processed values
    int processed_values[5];

    // Process each number with a combination of mathematical operations
    for (int i = 0; i < 5; i++) {
        // Apply a series of transformations: square, add a random offset, and take the modulus
        int offset = rand() % 100;
        processed_values[i] = (pow(numbers[i], 2) + offset) % 100000;

        // Introduce a conditional transformation involving square roots
        if (processed_values[i] % 2 == 0) {
            //-copilot next line-
        } else {
            //-copilot next line-
        }
    }

    // Output parsed results for further manipulation or display

    //-copilot next line-
}
```