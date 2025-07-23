```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function description: Calculate the total annual rainfall 
// Requirement: Use an external function `getMonthlyRainfall(int month)` to get the rainfall for a given month.
// The task is to sum up the rainfall over all 12 months and return the total.

extern int getMonthlyRainfall(int month);

int calculateAnnualRainfall() {
    int totalRainfall = 0;

    // Sum the rainfall for the entire year (January to December)
    for (int month = 1; month <= 12; month++) {
        totalRainfall += getMonthlyRainfall(month);
    }

    return totalRainfall;
}

int main(int argc, char *argv[]) {
    
    int annualRainfall;

    // Call the function to calculate the total rainfall for the year
    //-copilot next line-
}
```