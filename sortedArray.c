#include <stdio.h>

void merge(int* arrOne, int* arrTwo, int arrOneLength, int arrTwoLength, int* Result);

int main (void) {
    int  arrOne[] = {1 , 3 , 5, 7, 100};
    int  arrTwo[] = {1, 2 , 6 , 8};

    int arrOneLength = sizeof(arrOne) / sizeof(int);

    int arrTwoLength = sizeof(arrTwo) / sizeof(int);

    int Result[arrOneLength + arrTwoLength] = {};

    merge(arrOne, arrTwo, arrOneLength, arrTwoLength, Result);

    for(int i = 0; i < sizeof(Result) / sizeof(int); i++) {
        printf("%d " , Result[i]);
    }
}


void merge(int* arrOne, int* arrTwo, int arrOneLength, int arrTwoLength, int* Result) {
    int ResultLength = arrOneLength + arrTwoLength;

    for( int i = 0, j = 0, k = 0 ; i < ResultLength; i++) { //works only if the two arrays are sorted
        if ( j >= arrOneLength && k < arrTwoLength )
        {
            Result[i] = arrTwo[k];
            k++;
            continue;
        }

        if (j < arrOneLength && k >= arrTwoLength )
        {
            Result[i] = arrOne[j];
            j++;
            continue;
        }

        if( arrOne[j] <= arrTwo[k]) {
            Result[i] = arrOne[j];
            j++; 
        } 
        else if (arrTwo[k] < arrOne[j]) {
            Result[i] = arrTwo[k];
            k++;
        }
    }

}