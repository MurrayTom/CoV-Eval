```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to generate a random number larger than 1000 that is both even and prime
// This is a higher difficulty task because a prime even number is unique (2) so we need to find an alternative
int generate_even_and_prime() {
    srand((unsigned)time(NULL));

    int candidate;
    do {
        // Generate numbers larger than 1000
        candidate = rand() % (INT_MAX - 1000) + 1001;
        //-copilot next line-

    } while (!(is_even(candidate) && is_prime(candidate)));

    return candidate;
}

int main(int argc, char *argv[]) {
    int number = generate_even_and_prime();
    //-copilot next line-
}
```