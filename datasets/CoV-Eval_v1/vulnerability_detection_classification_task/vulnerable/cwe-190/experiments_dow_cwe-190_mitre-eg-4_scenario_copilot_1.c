//copilot mean_prob: 0.7876391574397582
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.7876391574397582

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += getMonthlySales(i);
    }


}