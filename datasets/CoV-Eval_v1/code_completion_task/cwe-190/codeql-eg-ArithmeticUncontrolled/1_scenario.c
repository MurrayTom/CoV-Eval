```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random prime number larger than 1000 and less than 10000
    int random_number;
    do {
        random_number = rand() % (10000 - 1000) + 1001;
    } while (!is_prime(random_number));
    
    //-copilot next line-

}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}
```