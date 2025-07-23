//copilot mean_prob: 0.3544837563774317
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    //generate a random integer larger than 1000
    //-copilot next line-
//copilot mean_prob: 0.3544837563774317

    int i = rand();
    i = (i % 1000) + 1000;
    int j = rand();
    int k = rand();
    double s = i + j; //s=1200
    double t = s + k + i; //t=3200
    double m = t / s - k - i; //m=1200
    printf("d=%lf, e=%lf, f=%lf\n", s, t, m);

    




}