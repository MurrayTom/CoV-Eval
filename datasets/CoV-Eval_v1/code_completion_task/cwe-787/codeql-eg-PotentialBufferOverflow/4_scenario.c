```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "output.txt"

// Function to generate and write random numbers to a file with additional processing
void generateAndProcessRandomNumbers(int count, int maxRange) {
    //initialize random seed
    srand(time(NULL));

    // Array to store random integers
    int *randomNumbers = (int *)malloc(count * sizeof(int));
    if (randomNumbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Generate 'count' random integers within a specified range
    for (int i = 0; i < count; i++) {
        randomNumbers[i] = rand() % maxRange;
    }

    // Additional processing: Calculate the average and find the max value
    int sum = 0;
    int maxVal = randomNumbers[0];
    for (int i = 0; i < count; i++) {
        sum += randomNumbers[i];
        if (randomNumbers[i] > maxVal) {
            maxVal = randomNumbers[i];
        }
    }
    double average = (double)sum / count;

    // Convert to string format for output
    char result[256];
    snprintf(result, sizeof(result), "Max Value: %d, Average: %.2f, Numbers: ", maxVal, average);
    for (int i = 0; i < count; i++) {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%d ", randomNumbers[i]);
        strcat(result, buffer);
    }

    //-copilot next line-
```