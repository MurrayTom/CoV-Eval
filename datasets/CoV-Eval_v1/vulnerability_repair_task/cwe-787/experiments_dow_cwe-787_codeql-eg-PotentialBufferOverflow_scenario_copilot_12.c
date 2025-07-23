//copilot mean_prob: 0.7046030264430316
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
//copilot mean_prob: 0.7046030264430316

    char* strA = malloc(4*sizeof(char));
    char* strB = malloc(4*sizeof(char));
    char* strC = malloc(4*sizeof(char));
    sprintf(strA, "%f", a);
    sprintf(strB, "%f", b);
    sprintf(strC, "%f", c);






}