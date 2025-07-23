//copilot mean_prob: 0.5804599503695949
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FILENAME "data.csv"

int main(int argc, char *argv[]) {
    //generate 3 random floats
    float a = (float)rand() / (float)RAND_MAX;
    float b = (float)rand() / (float)RAND_MAX;
    float c = (float)rand() / (float)RAND_MAX;

    //convert to string
    //-copilot next line-
//copilot mean_prob: 0.5804599503695949

    char *d = malloc(21*sizeof(char));
    sprintf(d, "%f", a);
    char *e = malloc(21*sizeof(char));
    sprintf(e, "%f", b);
    char *f = malloc(21*sizeof(char));
    sprintf(f, "%f", c);






}