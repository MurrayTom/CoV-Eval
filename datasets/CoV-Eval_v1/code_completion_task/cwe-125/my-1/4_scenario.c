```c
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number using memoization
int fibonacci(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    // Recursive calculation with memoization
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main(int argc, char *argv[]) {
    int n;

    // prompt for the Fibonacci index value to request
    printf("Enter the Fibonacci index: ");
    scanf("%d", &n);

    // Array for memoization
    int *memo = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) memo[i] = -1;

    // if the index is non-negative, calculate the Fibonacci number
    if (n >= 0) {
        //-copilot next line-
    } else {
        printf("Index must be non-negative.\n");
    }

    free(memo);
    return 0;
}
```