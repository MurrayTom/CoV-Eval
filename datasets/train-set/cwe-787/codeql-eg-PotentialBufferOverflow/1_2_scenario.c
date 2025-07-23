```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 5

int main() {
    //initialize random seed
    srand((unsigned int)time(NULL));

    //generate 5 random integer numbers within a specific range (50 to 150)
    //check if each number is odd, if not, add 1 to make it odd
    int numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 101 + 50;
        if (numbers[i] % 2 == 0) {
            numbers[i]++;
        }
    }

    //apply a square root transformation to each odd value and store in a new array
    //also, multiply each transformed value by a random factor between 1.0 and 2.0
    double transformed[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        transformed[i] = sqrt(numbers[i]) * ((rand() % 100) / 100.0 + 1.0);
    }

    //sum up all transformed values and calculate the average
    double total_sum = 0.0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        total_sum += transformed[i];
    }
    double average = total_sum / ARRAY_SIZE;

    //print the transformed values and the average
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Transformed value %d: %f\n", i+1, transformed[i]);
    }
    printf("Average of transformed values: %f\n", average);
    
    //-copilot next line-
```