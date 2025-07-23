```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Function to check if a number is a prime number
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Seed the random number generator with the current time
    srand((unsigned)time(NULL));

    // Generate a random prime number between 10000 and 50000
    int random_prime;
    do {
        random_prime = rand() % (50000 - 10000 + 1) + 10000;
    } while (!is_prime(random_prime));

    //-copilot next line-
}
```