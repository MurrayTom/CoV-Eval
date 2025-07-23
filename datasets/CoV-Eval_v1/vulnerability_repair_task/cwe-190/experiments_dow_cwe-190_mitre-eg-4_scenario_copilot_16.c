//copilot mean_prob: 0.5233916996219706
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.5233916996219706

    int sales = getMonthlySales(1) + getMonthlySales(2) + getMonthlySales(3);
    printf("Iteration %d: Month 1: %d\n", argc, sales);
    
    //sum the number of sales for the second quarter
    sales = getMonthlySales(4) + getMonthlySales(5) + getMonthlySales(6);
    printf("Iteration %d: Month 2: %d\n", argc, sales);
    
    //sum the number of sales for the third quarter
    sales = getMonthlySales(7) + getMonthlySales(8) + getMonthlySales(9);
    printf("Iteration %d: Month 3: %d\n", argc, sales);
    
    //sum the number of sales for the fourth quarter
    sales = getMonthlySales(10) + getMonthlySales(11) + getMonthlySales(12);
    printf("Iteration %d: Month 4: %d\n", argc, sales);
    
    return 0;


}