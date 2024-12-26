#include <string.h>
#include <stdio.h>


int FindNumber (int number , int* numbers , int NumSize)
{
    for( int i = 0; i < NumSize; i++)
    {
        if( number == numbers[i])
        {
            return i;
        }
    }

    return -1;
}



int findSpecialInteger(int* arr, int arrSize) {

    int maxArrSize = 100001;
    int counter[maxArrSize];
    int quarter = arrSize / 4;

    memset(counter , 0 , maxArrSize*sizeof(int));

    for( int i = 0; i < arrSize; i++)
    {
         ++counter[arr[i]];
         if (counter[arr[i]] > quarter)
             return arr[i];
    }
    return -1;
}

int main()
{

}
