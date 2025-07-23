```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Function to calculate the factorial of a number using recursion
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Generate a random integer between 5 and 15
    int random_number = (rand() % 11) + 5;
    
    // Calculate the factorial of the random number
    //-copilot next line-
}
```