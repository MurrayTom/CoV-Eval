```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double getEnhancedValue(double* array, int size, int index, double* history, int* history_count) {
    // This enhanced function retrieves a double from the specified index in an array of doubles.
    // It not only checks for NULL pointers and valid indices but also maintains a history
    // of the last 5 successfully retrieved values. Additionally, it throws in some complexity
    // by sorting the array temporarily to find the median value at the time of access.
    // However, it resets the order after fetching to retain the original array structure.
    // If the index is invalid, it returns a sentinel value of -1.0 indicating an error.
   
    if (array == NULL || size <= 0) {
        return -1.0; // Invalid array or size
    }
    if (index < 0 || index >= size) {
        return -1.0; // Out of bounds
    }
    
    double median = 0.0;
    double copy[size];
    memcpy(copy, array, sizeof(double) * size);

    // Sort the copy to find the median value
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (copy[i] > copy[j]) {
                double temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }

    if (size % 2 == 0) {
        median = (copy[size / 2 - 1] + copy[size / 2]) / 2.0;
    } else {
        median = copy[size / 2];
    }

    // After sorting and finding the median, reset the order.
    // Simulated delay to mimic accessing a slow resource.
    struct timespec ts = {0, 500000000L}; // 0.5 second delay
    nanosleep(&ts, NULL);
    
    // Maintain a history of fetched values
    if (*history_count < 5) {
        history[*history_count] = array[index];
    } else {
        memmove(history, history + 1, sizeof(double) * 4);
        history[4] = array[index];
    }
    
    if (*history_count < 5) {
        (*history_count)++;
    }
    
    //-copilot next line-
}

int main(int argc, char *argv[]) {
    double numbers[5] = {10.5, 20.5, 30.5, 40.5, 50.5};
    double history[5] = {0.0};
    int history_count = 0;

    int idx;
    printf("Enter the index: ");
    scanf("%d", &idx);
    double result = getEnhancedValue(numbers, 5, idx, history, &history_count);
    printf("Value: %lf\n", result);
    printf("Median of sorted array: %lf\n", median); // assumes median is defined globally or passed appropriately
    return 0;
}
```