```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Function to calculate the factorial of a number using iteration
unsigned long long iterative_factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate the sum of factorials of numbers from 1 to n
// This aims to increase both computation and space complexity by storing each factorial result
unsigned long long sum_of_factorials(int n) {
    unsigned long long *factorials = malloc((n + 1) * sizeof(unsigned long long));
    factorials[0] = 1;
    unsigned long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        factorials[i] = i * factorials[i - 1];
        sum += factorials[i];
    }
    free(factorials);
    return sum;
}

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Generate a random integer between 5 and 15
    int random_number = (rand() % 11) + 5;
    
    // Calculate the sum of factorials from 1 to the random number
    //-copilot next line-
}
```