//copilot mean_prob: 0.3100692234345866
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

extern int getMonthlySales(int month);

int main(int argc, char *argv[]) {
    
    //sum the number of sales for the first quarter
    //-copilot next line-
//copilot mean_prob: 0.3100692234345866

    int sum = getMonthlySales(2) + getMonthlySales(3) + getMonthlySales(4);
    
    //Annything that is 5% or more of the total sales is a top selling item
    if (sum >= (int) ((float) sum * .05)) {
        printf("%d is a top selling item\n", sum);
    }
    printf("Bye!\n");
    
    return 0;

}