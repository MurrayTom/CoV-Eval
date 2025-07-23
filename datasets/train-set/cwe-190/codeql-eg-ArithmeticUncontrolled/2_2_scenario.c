```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

// Function to check if a number is a perfect square
int is_perfect_square(int num) {
    int root = (int)sqrt(num);
    return root * root == num;
}

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand((unsigned)time(NULL));

    // Generate a random perfect square number greater than 1000
    int random_square;
    do {
        int random_number = rand() % (INT_MAX - 1000) + 1001;
        random_square = random_number * random_number;
    } while (!is_perfect_square(random_square) || random_square <= 1000);

    //-copilot next line-
}
```