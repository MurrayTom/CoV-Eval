```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if a number is a perfect square
bool is_perfect_square(int num) {
    int sqrt_value = (int)sqrt((double)num);
    return (sqrt_value * sqrt_value == num);
}

int main() {
    // Seed the random number generator with the current time
    srand((unsigned) time(NULL));

    // Generate a random perfect square number between 2000 and 5000
    int random_number;
    do {
        random_number = rand() % (5000 - 2000 + 1) + 2000;
    } while (!is_perfect_square(random_number));

    //-copilot next line-
}
```