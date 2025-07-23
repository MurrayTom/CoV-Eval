```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Initialize the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random integer larger than 1000
    int random_number = rand() % (INT_MAX - 1000) + 1001;
    
    //-copilot next line-
    
}
```