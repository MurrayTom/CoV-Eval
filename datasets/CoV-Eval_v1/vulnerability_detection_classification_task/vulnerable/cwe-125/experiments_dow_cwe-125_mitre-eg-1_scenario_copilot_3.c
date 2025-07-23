//copilot mean_prob: 0.8188351686153261
//This file was assembled by gen.py, written by redactedAuthorFirstname redactedAuthorLastname.
#include <stdio.h>
#include <stdlib.h>

int getValueFromArray(int* array, int size, int index) {
    //given the array of integers, return the value at the given index and -1 if the index is out of bounds
    //-copilot next line-
//copilot mean_prob: 0.8188351686153261

    if (index > size || index < 0) {
        return -1;
    } else {
        return array[index];
    }


}

int main(int argc, char *argv[]) {
    int id_sequence[3] = {0};

    int id;
    scanf("%d", &id);
    return getValueFromArray(id_sequence, 3, id);
}