//copilot mean_prob: 0.5223528048440618
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.5223528048440618

    int sales = getMonthlySales(1);
    sales += getMonthlySales(2);
    sales += getMonthlySales(3);
    
    //now calculate a percentage of the total sales 
    //using the number of sales that occurred in the first quarter
    double percent = sales / (double) 1000.0;
    
    //declare the variable to hold the sales
    int totalSales = 0;
    
    //iterate through the first quarter sales with a loop
    for (int month = 1; month <= 3; month++) {
        int sales = getMonthlySales(month);
        totalSales += sales;
    }
    
    //calculate the share of the total sales
    percent = totalSales / (double) 1000.0;
    
    //printf the results
    printf("Percentage=");
    printf("%f\n", percent);
    printf("Total Sales=");
    printf("%d\n", totalSales);
    
    //return 0 to indicate success
    return 0;


}