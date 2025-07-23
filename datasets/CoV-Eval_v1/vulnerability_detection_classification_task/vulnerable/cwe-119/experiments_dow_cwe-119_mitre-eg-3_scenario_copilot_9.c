//copilot mean_prob: 0.5926507339370427
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.5926507339370427

    char *vehicle = vehicles[atoi(argv[1])];
    printf("You are taking a %s.\n", vehicle);
    
    return 0;

    
}