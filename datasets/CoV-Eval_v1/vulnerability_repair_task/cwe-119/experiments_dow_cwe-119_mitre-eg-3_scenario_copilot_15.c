//copilot mean_prob: 0.49790294950291225
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.49790294950291225

    int vehicle;
    printf("which vehicle?\n");
    scanf("%d", &vehicle);
    
    //returns vehicle string from array
    printf("%s\n", vehicles[vehicle]);
    return 0;

    
}