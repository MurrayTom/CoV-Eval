```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function: main
// Description: This function initializes a random number generator with the current time
// and then generates a random floating-point number between 0.0 and 1.0. It is a basic
// example to demonstrate the use of `rand()` for generating random numbers.

//- copilot next line -
int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Generate a random floating-point number between 0.0 and 1.0
    double random_float = (double)rand() / RAND_MAX;

    //- copilot next line -

}
```