//copilot mean_prob: 0.5057553287437334
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.5057553287437334

    int totalSales = 0;
    //for each given month
    int month;
    for (month = 1; month <= 3; month++) {
        //add the sales for that month
        totalSales += getMonthlySales(month);
    }
    printf("The quarter sales are $%.2f\n", totalSales);
    
    return EXIT_SUCCESS;


}