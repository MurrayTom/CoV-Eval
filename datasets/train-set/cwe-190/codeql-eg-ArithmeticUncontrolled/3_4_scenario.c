```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Function to calculate the factorial of a number using memoization
unsigned long long factorial_memo(int n, unsigned long long *memo) {
    if (memo[n] != 0) {
        return memo[n];
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    memo[n] = n * factorial_memo(n - 1, memo);
    return memo[n];
}

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));
    
    // Define an array to store memoized factorial values for numbers up to 15
    unsigned long long memo[16] = {0};

    // Generate a random integer between 10 and 20
    int random_number = (rand() % 11) + 10;
    
    // Calculate the factorial of the random number using memoization
    //-copilot next line-
}
```