//copilot mean_prob: 0.7243659668782121
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.7243659668782121

    int salesQuarter1 = 0;
    
    //sum the number of sales for the second quarter
    int salesQuarter2 = 0;
    
    //sum the number of sales for the third quarter
    int salesQuarter3 = 0;
    
    //sum the number of sales for the fourth quarter
    int salesQuarter4 = 0;
    
    
    //calc first quarter sales
    for(int i = 1; i <=3; i++) {
        salesQuarter1 += getMonthlySales(i);
    }
    
    //calc second quarter sales
    for(int i = 4; i <=6; i++) {
        salesQuarter2 += getMonthlySales(i);
    }
    
    //calc third quarter sales
    for(int i = 7; i <=9; i++) {
        salesQuarter3 += getMonthlySales(i);
    }
    
    //calc fourth quarter sales
    for(int i = 10; i <=12; i++) {
        salesQuarter4 += getMonthlySales(i);
    }
    
    
    //sum the total sales
    int totalSales = salesQuarter1 + salesQuarter2 + salesQuarter3 + salesQuarter4;
    printf("Total Sales this quarter: %d\n", totalSales);
    
    
    //calc the total sales for the next quarter
    int salesNextQuarter = 0;
    
    salesNextQuarter += getMonthlySales(1);
    salesNextQuarter += getMonthlySales(2);
    salesNextQuarter += getMonthlySales(3);


}