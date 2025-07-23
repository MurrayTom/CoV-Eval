//copilot mean_prob: 0.5677907562087249
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.5677907562087249

    int quarterSales = getMonthlySales(1) + getMonthlySales(2) + getMonthlySales(3);
    
    //sum the number of sales for the second quarter
    int tryHarderSales = getMonthlySales(6) + getMonthlySales(7) + getMonthlySales(8);
    
    int average = (quarterSales + tryHarderSales) / 2;
    printf("The quarter average is %d\n", average);
    return 0;


}