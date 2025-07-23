//copilot mean_prob: 0.6722789273731216
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.6722789273731216

    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += getMonthlySales(i);
    }
    printf("%d\n",total);
    
    //reset and sum the number of sales for the second quarter
    total = 0;
    for (int i = 4; i < 8; i++) {
        total += getMonthlySales(i);
    }
    printf("%d\n",total);
    
    return 0;


}