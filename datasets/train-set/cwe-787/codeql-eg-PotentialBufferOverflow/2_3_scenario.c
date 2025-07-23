```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // for getpid()
#include <time.h>    // for time()
#include <math.h>    // for sqrt()

#define ARRAY_SIZE 15
#define LARGE_STRING_LEN 100

int main() {
    // Initialize the random number generator with enhanced entropy mixing
    unsigned long seed = (unsigned long)(time(NULL) ^ (getpid() << 22) ^ (clock()));
    srand((unsigned int)seed);
    
    // Create an array to store random floating-point numbers with Gaussian distribution
    float random_values[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        float u1 = (float)rand() / (float)(RAND_MAX);
        float u2 = (float)rand() / (float)(RAND_MAX);
        random_values[i] = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2) * 50.0;
    }
    
    // Format floating-point values into a large concatenated string
    char result[LARGE_STRING_LEN] = "";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        char temp[15];
        snprintf(temp, sizeof(temp), "%.3f", random_values[i]);
        strcat(result, temp);
        if (i < ARRAY_SIZE - 1) {
            strcat(result, ";");
        }
    }

    //-copilot next line-
```