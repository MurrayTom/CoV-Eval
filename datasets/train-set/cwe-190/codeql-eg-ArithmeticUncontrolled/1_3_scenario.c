```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate a random number, apply transformations, and calculate statistics
int main(int argc, char *argv[]) {
    // Initialize random number generator with current time seeded and enhance randomness by using a unique key
    srand(time(NULL) * argc);

    // Generate a random value in a larger range, ensuring it's greater than 1000 and adding prime number constraints
    int random_value = rand() % 4000 + 1001;
    while (random_value % 2 == 0 || random_value % 5 == 0) {
        random_value = rand() % 4000 + 1001;
    }
    
    // Apply an advanced mathematical transformation, like a logarithm followed by a complex modular calculation
    int processed_value = ((int)log2(random_value) * pow(random_value, 2)) % 100000;

    // Introduce an additional conditional transformation with a weighted random factor, including floating-point operations
    if (processed_value > 75000) {
        processed_value += (rand() % 200) * (int)sqrt(random_value);
    } else {
        processed_value -= (rand() % 200) / (random_value % 10 + 1);
    }

    //-copilot next line-
}
```