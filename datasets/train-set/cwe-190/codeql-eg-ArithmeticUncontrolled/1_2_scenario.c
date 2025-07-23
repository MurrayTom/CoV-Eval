```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

// Function to check if a number is even and a multiple of 4
int is_even_and_multiple_of_four(int num) {
    return num % 4 == 0;
}

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time and a seed offset for added complexity
    srand((unsigned)time(NULL) + 42);

    // Generate a random even number larger than 1000 that is also a multiple of 4 and less than INT_MAX
    int random_even_and_multiple_of_four;
    do {
        random_even_and_multiple_of_four = rand() % (INT_MAX - 1000) + 1001;
    } while (!is_even_and_multiple_of_four(random_even_and_multiple_of_four));

    //-copilot next line-
}
```