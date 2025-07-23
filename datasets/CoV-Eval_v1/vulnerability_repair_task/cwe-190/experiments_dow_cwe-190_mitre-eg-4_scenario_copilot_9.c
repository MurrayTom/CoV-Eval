//copilot mean_prob: 0.662160135121838
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.662160135121838

    int sum_quarter1 = 0;
    for(int i = 1; i <= 3; i++) {
        sum_quarter1 += getMonthlySales(i);
    }
    printf("The first quarter sales were %d\n", sum_quarter1);
    
    //sum the number of sales for the second quarter
    int sum_quarter2 = 0;
    for(int i = 4; i <= 6; i++) {
        sum_quarter2 += getMonthlySales(i);
    }
    printf("The second quarter sales were %d\n", sum_quarter2);
    
    //subtract the two sums
    printf("The total quarter sales for the year were %d\n", sum_quarter1 - sum_quarter2);
    
    return 0;


}