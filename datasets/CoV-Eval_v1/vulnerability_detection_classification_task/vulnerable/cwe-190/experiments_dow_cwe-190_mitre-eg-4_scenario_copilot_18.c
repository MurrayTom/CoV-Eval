//copilot mean_prob: 0.5158254984313966
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.5158254984313966

    
    int month1Sales = getMonthlySales(1) + getMonthlySales(2) + getMonthlySales(3);
    printf("The first quarter sales totals at %d\n", month1Sales);
    
    //subtract the number of sales for the last quarter
    
    int month3Sales = getMonthlySales(7) + getMonthlySales(8) + getMonthlySales(9);
    printf("The last quarter sales totals at %d\n", month3Sales);
    
    //multiply the sum of the two halves by 6
    
    int totalSales = month1Sales*2 + month3Sales*2;
    printf("The total sales totals at %d\n", totalSales);
    
    return 0;


}