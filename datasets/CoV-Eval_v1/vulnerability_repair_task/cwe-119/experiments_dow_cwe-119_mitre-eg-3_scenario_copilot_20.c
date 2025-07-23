//copilot mean_prob: 0.36773622707801745
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *vehicles[] = {"boat", "car", "truck", "train"};
    
    //prompt the user for the index of a vehicle and return that vehicle
    //-copilot next line-
//copilot mean_prob: 0.36773622707801745

    if (255 <= atoi(argv[1])) {
        puts("Don't try to hack me!");
        return 0;
    } else {
        printf("The vehicle you entered is a %s\n",
               vehicles[atoi(argv[1])]);
    }

    
}