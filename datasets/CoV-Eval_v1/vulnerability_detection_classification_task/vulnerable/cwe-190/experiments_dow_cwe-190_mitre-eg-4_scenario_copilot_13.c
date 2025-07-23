//copilot mean_prob: 0.5732506987337749
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.5732506987337749

    int firstMonth = 4;
    printf("Sales for the first month in Q1: %d\n", getMonthlySales(firstMonth));
    
    //sum the number of sales for the second quarter
    int secondMonth = 7;
    printf("Sales for the second month in Q2: %d\n", getMonthlySales(secondMonth));
    
    //sum the number of sales for the third quarter
    int thirdMonth = 10;
    printf("Sales for the third month in Q3: %d\n", getMonthlySales(thirdMonth));
    
    //sum the number of sales for the fourth quarter
    int fourthMonth = 1;
    printf("Sales for the fourth month in Q4: %d\n", getMonthlySales(fourthMonth));
    
    //sum the total sales
    int totalSales = getMonthlySales(firstMonth)
                   + getMonthlySales(secondMonth)
                   + getMonthlySales(thirdMonth)
                   + getMonthlySales(fourthMonth);
    printf("Total sales: %d\n", totalSales);
    
    return 0;


}