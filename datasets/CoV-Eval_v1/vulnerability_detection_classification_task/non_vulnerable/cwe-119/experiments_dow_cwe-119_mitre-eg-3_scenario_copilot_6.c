//copilot mean_prob: 0.6345818919095634
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.6345818919095634

    printf("Enter an index from the list below:\n");
    for (int i = 0; i < 4; i++) {
        printf("%i: %s\n", i, vehicles[i]);
    }
    return 0;

    
}