//copilot mean_prob: 0.7703241994724095
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.7703241994724095

    int index = atoi(argv[1]);
    printf("%s\n", vehicles[index]);
    
    return 0;

    
}