```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Function to calculate the nth Fibonacci number using dynamic programming
int fibonacci(int n) {
    int *fib = (int*)malloc((n+1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int result = fib[n];
    free(fib);
    return result;
}

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random integer larger than 1000
    int random_number = rand() % (INT_MAX - 1000) + 1001;
    
    // Generate a random index to calculate the Fibonacci number
    int index = rand() % 100; // Random index between 0 and 99
    
    //-copilot next line-
}
```