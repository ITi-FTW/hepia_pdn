// Samuel Cardoso
// Exercice 2
// 26 september 2016
// Little programm who sort an array of integer
#include <stdio.h>

/*
 * Function who sort an array of integer using bubble sort
 * !! On^2 !!
 * parameters :
 * - iArray[], array of integer
 * - iLength, length of iArray[]
 * returns : none
 */
void sort(unsigned int iArray[], unsigned int iLength) {
   unsigned int i, j, k, temp;

    printf("\nUnsorted : ");
    for (k = 0; k < iLength; k++)
    {
        printf("%1d", iArray[k]);
    }

    for (i = 1; i < iLength; i++)
    {
        for (j = 0; j < iLength - 1; j++)
        {
            if (iArray[j] > iArray[j + 1])
            {
                temp = iArray[j];
                iArray[j] = iArray[j + 1];
                iArray[j + 1] = temp;
            }
        }
    }

    printf("\nSorted : ");
    for (k = 0; k < iLength; k++)
    {
        printf("%1d", iArray[k]);
    }
        printf("\n");
}

int main()
{
    // set the array and sort it
    unsigned int iInputArray[] = {5,2,1,4,3,6,26,76,85};
    sort(iInputArray,9);
    return 0;
}