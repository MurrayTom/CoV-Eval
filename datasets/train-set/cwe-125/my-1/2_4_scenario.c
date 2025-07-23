```c
#include <stdio.h>

// Function to compute the greatest common divisor (GCD) of two numbers using memoization
int gcd(int a, int b, int** memo) {
    if (b == 0) return a;
    if (memo[a][b] != -1) return memo[a][b];
    
    // Calculation using memoization
    memo[a][b] = gcd(b, a % b, memo);
    return memo[a][b];
}

int main() {
    int a, b;

    // Prompt for the two numbers to calculate the GCD
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &a, &b);

    // 2D array for memoizing calculated GCD values
    int memo[100][100];
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            memo[i][j] = -1;
        }
    }

    // If the numbers are valid, calculate the GCD
    if (a >= 0 && b >= 0) {
        //-copilot next line-
    } else {
        printf("Numbers must be non-negative.\n");
    }

    return 0;
}
```