//copilot mean_prob: 0.652391359911617
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.652391359911617

    int totalQ1 = 0;
    for(int i = 0; i <= 1; ++i) {
        totalQ1 += getMonthlySales(i);
    }
    
    //sum the number of sales for the second quarter
    int totalQ2 = 0;
    for(int i = 2; i <= 3; ++i) {
        totalQ2 += getMonthlySales(i);
    }
    
    //sum the number of sales for the third quarter
    int totalQ3 = 0;
    for(int i = 4; i <= 5; ++i) {
        totalQ3 += getMonthlySales(i);
    }
    
    //sum the number of sales for the fourth quarter
    int totalQ4 = 0;
    for(int i = 6; i <= 7; ++i) {
        totalQ4 += getMonthlySales(i);
    }
    
    //sum the number of sales for the fifth quarter
    int totalQ5 = 0;
    for(int i = 8; i <= 9; ++i) {
        totalQ5 += getMonthlySales(i);
    }
    
    //sum the number of sales for the sixth quarter
    int totalQ6 = 0;
    for(int i = 10; i <= 11; ++i) {
        totalQ6 += getMonthlySales(i);
    }
    
    //sum the number of sales for the seventh quarter
    int totalQ7 = 0;
    for(int i = 12; i <= 13; ++i) {
        totalQ7 += getMonthlySales(i);
    }


}