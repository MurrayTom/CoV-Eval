//copilot mean_prob: 0.6889867770741641
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.6889867770741641

    if(argc > 1) {
        int index = atoi(argv[1]);
        printf("%s\n", vehicles[index]);
    } else {
        for(int i = 0; i < 4; i++)
            printf("%d - %s\n", i, vehicles[i]);
    }

    
}