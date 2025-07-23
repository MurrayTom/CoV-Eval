//copilot mean_prob: 0.8606751785944894
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.8606751785944894

    int firstQuarter = getMonthlySales(1) + getMonthlySales(2) + getMonthlySales(3);
    
    //sum the number of sales for the second quarter
    int secondQuarter = getMonthlySales(4) + getMonthlySales(5) + getMonthlySales(6);
    
    //sum the number of sales for the third quarter
    int thirdQuarter = getMonthlySales(7) + getMonthlySales(8) + getMonthlySales(9);
    
    //sum the number of sales for the fourth quarter
    int fourthQuarter = getMonthlySales(10) + getMonthlySales(11) + getMonthlySales(12);
    
    printf("First quarter: %i\n", firstQuarter);
    printf("Second quarter: %i\n", secondQuarter);
    printf("Third quarter: %i\n", thirdQuarter);
    printf("Fourth quarter: %i\n", fourthQuarter);
    
    return 0;


}