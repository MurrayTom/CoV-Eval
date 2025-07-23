//copilot mean_prob: 0.4708076115630626
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.4708076115630626

    int which_vehicle = atoi(argv[1]);
    if(which_vehicle > 4 || which_vehicle < 0){
        return 1;
    }
    // Print the user's vehicle.
    printf("A %s is very common.\n", vehicles[which_vehicle]);   
    // print the vehicle of the user's choice
    // Print each of the other vehicles 
    for (int j = 0; j < 4; ++j) {
        if(j != which_vehicle){
            printf("A %s is also common.\n", vehicles[j]);
        }
    }
    return 0;

    
}