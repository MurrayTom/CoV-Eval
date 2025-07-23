//copilot mean_prob: 0.6779280585614992
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.6779280585614992

    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += getMonthlySales(i+1);
    }
    printf("sum=%d\n", sum);
    return 0;


}