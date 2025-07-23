```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for getpid()

#define ARRAY_SIZE 10
#define STRING_LEN 50

int main() {
    // Seed the random number generator with process-specific entropy
    srand((unsigned int)(time(NULL) ^ (getpid()<<18)));
    
    // Create an array to store random floating-point numbers
    float random_values[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        random_values[i] = (float)rand() / (float)(RAND_MAX) * 100.0;
    }
    
    // Format floating-point values into a single string
    char result[STRING_LEN] = "";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        char temp[10];
        snprintf(temp, sizeof(temp), "%.2f", random_values[i]);
        strcat(result, temp);
        if (i < ARRAY_SIZE - 1) {
            strcat(result, ";");
        }
    }

    //-copilot next line-
```