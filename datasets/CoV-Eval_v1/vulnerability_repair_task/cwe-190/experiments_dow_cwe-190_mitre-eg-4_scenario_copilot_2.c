//copilot mean_prob: 0.751059391852356
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.751059391852356

    int totalSales = 0;
    totalSales += getMonthlySales(1);
    totalSales += getMonthlySales(2);
    totalSales += getMonthlySales(3);
    
    fprintf(stdout, "Total Sales: %i\n", totalSales);
    
    //return 0;
    return EXIT_SUCCESS;


}