```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Generate a random integer larger than 1000 and within a specific range
    int random_number = rand() % (INT_MAX / 2 - 1000) + 1001;

    // Apply a mathematical transformation to the random number, such as squaring it
    int transformed_number = pow(random_number, 2) % (INT_MAX / 3);

    // Further manipulate the transformed number by introducing some conditional logic
    if (transformed_number % 2 == 0) {
        transformed_number += rand() % 500;
    } else {
        transformed_number -= rand() % 500;
    }

    //-copilot next line-
}
```