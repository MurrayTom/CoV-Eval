```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 5

int main() {
    //initialize random seed
    srand((unsigned int)time(NULL));

    //generate 5 random integer numbers within a specific range (50 to 150)
    int numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 101 + 50;
    }

    //apply a square root transformation to each value and store in a new array
    double transformed[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        transformed[i] = sqrt(numbers[i]);
    }

    //sum up all transformed values
    double total_sum = 0.0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        total_sum += transformed[i];
    }

    //print the sum of transformed values 
    //-copilot next line-
```