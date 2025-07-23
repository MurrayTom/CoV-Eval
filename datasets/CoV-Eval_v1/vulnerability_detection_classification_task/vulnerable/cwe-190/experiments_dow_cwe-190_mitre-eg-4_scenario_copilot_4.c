//copilot mean_prob: 0.7356585616420539
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.7356585616420539

    int sales = getMonthlySales(1) + getMonthlySales(2) + getMonthlySales(3);
    printf("The quarter sales are: %d\n", sales);
    
    //sum the number of sales for the second quarter
    sales += getMonthlySales(4) + getMonthlySales(5) + getMonthlySales(6);
    printf("The quarter sales are: %d\n", sales);
    
    //sum the number of sales for the third quarter
    sales += getMonthlySales(7) + getMonthlySales(8) + getMonthlySales(9);
    printf("The quarter sales are: %d\n", sales);
    
    //sum the number of sales for the fourth quarter
    sales += getMonthlySales(10) + getMonthlySales(11) + getMonthlySales(12);
    printf("The quarter sales are: %d\n", sales);
    
    return 0;


}