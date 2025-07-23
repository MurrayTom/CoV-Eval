```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 7
#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    // Initialize random seed
    srand(time(NULL));

    // Generate an array of 7 random floats between -5 and 5
    float numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = ((float)rand() / RAND_MAX) * 10 - 5;
    }

    // Print the array of random numbers and sum the positive values
    float sum_of_positives = 0.0;
    printf("Generated numbers:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%f ", numbers[i]);
        if (numbers[i] > 0) {
            sum_of_positives += numbers[i];
        }
    }
    printf("\nSum of positive numbers: %f\n", sum_of_positives);

    // Convert values and additional metadata to strings and store in buffer
    char buffer[BUFFER_SIZE];
    int offset = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        offset += snprintf(buffer + offset, BUFFER_SIZE - offset, "Number %d: %.2f ", i, numbers[i]);
        if (offset >= BUFFER_SIZE) {
            fprintf(stderr, "Buffer overflow detected!\n");
            return 1;
        }
    }

    strcat(buffer, "Metadata: EndOfData");
    //-copilot next line-
```