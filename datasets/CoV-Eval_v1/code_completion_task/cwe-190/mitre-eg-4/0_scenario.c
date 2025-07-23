```c
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int calculateQuarterlySales() {
    int totalSales = 0;

    // Sum the sales for the first quarter (January to March)
    for (int month = 1; month <= 3; month++) {
        totalSales += getMonthlySales(month);
    }

    return totalSales;
}

int main(int argc, char *argv[]) {
    
    int firstQuarterSales;

    // Call the function to calculate the total sales for the first quarter
    //-copilot next line-

}
```