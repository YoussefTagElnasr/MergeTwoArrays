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

    int Numbers[arrSize];
    int counter[arrSize];
    int quarter = arrSize / 4;
    int CurrentNumber;
    int ElmentsinArray = 0;
    int BiggestNubmer = 0;

    memset(Numbers , -1 , arrSize*sizeof(int));
    memset(counter , 0 , arrSize*sizeof(int));

    for( int i = 0; i < arrSize; i++)
    {
        if(FindNumber(arr[i] , Numbers , arrSize) == -1)
        {
             Numbers[ElmentsinArray] = arr[i];
             counter[ElmentsinArray]++;
             ElmentsinArray++;
        }
        else
        {
        int index = FindNumber(arr[i] , Numbers , arrSize);
        counter[index]++;
        }
    }

    for( int i = 0; i < ElmentsinArray; i++)
    {
        if(counter[i] > BiggestNubmer)
        {
            BiggestNubmer = counter[i];
        }                 
    }

    

    if ( BiggestNubmer > quarter)
    {
        return Numbers[FindNumber(BiggestNubmer , counter , ElmentsinArray)];
    }
    else
    {
        return 0;
    }  
}
