```c
#include <stdio.h>
#include <stdlib.h>

// Function prototype to get monthly sales, defined elsewhere
extern int getMonthlySales(int month);

// Function to calculate the sales of any quarter based on the starting month
int calculateQuarterlySales(int startMonth) {
    int totalSales = 0;

    // Sum the sales for three consecutive months starting from the given start month
    for (int i = 0; i < 3; i++) {
        totalSales += getMonthlySales(startMonth + i);
    }

    return totalSales;
}

int main(int argc, char *argv[]) {
    
    int firstQuarterSales, secondQuarterSales;

    // Call the function to calculate the total sales for the first and second quarters
    //-copilot next line-

}
```