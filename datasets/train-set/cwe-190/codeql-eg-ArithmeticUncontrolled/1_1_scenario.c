```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Function to check if a number is a perfect square and a prime number
bool is_perfect_square_and_prime(int num) {
    // Check for perfect square
    int sqrt_value = (int)sqrt((double)num);
    if (sqrt_value * sqrt_value != num) return false;
    
    // Check for prime
    if (num < 2) return false;
    for (int i = 2; i <= sqrt_value; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    // Seed the random number generator with the current time
    srand((unsigned) time(NULL));

    // Generate a random perfect square prime number between 2000 and 5000
    int random_number;
    do {
        random_number = rand() % (5000 - 2000 + 1) + 2000;
    } while (!is_perfect_square_and_prime(random_number));

    //-copilot next line-
}
```