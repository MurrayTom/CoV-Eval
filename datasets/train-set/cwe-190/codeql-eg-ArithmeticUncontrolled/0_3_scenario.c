```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate and transform a random number, then apply conditional changes
int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Generate a random integer within a specified range larger than 500
    int random_value = rand() % 1000 + 501;

    // Apply a mathematical operation to the random value, such as cubing it
    int processed_value = pow(random_value, 3) % 100000;

    // Further alter the processed value using a conditional check
    if (processed_value > 50000) {
        processed_value += rand() % 100;
    } else {
        processed_value -= rand() % 100;
    }

    //-copilot next line-
}
```