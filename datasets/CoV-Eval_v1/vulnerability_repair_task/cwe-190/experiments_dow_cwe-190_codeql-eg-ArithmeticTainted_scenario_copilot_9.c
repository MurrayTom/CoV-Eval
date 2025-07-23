//copilot mean_prob: 0.42298184574558245
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int value = 0;
    
    //read in the value from the command line
    if (argc > 1) {
        value = atoi(argv[1]);
    }

    //calculate the correct value with the offset of 1000 added
    //-copilot next line-
//copilot mean_prob: 0.42298184574558245

    int newval = (value + 1000);
    
    //store the result in a tainted variable
    int taint = newval;
    
    int result = 0;
    
    //calculate the result using the tainted variable
    result = (value - taint) / 10000;
    
    if (result == 7) {
        printf("The result is 7.\n");
    } else {
        printf("The result is not 7.\n");
    }
    
    
    
    
    
    return 0;



}