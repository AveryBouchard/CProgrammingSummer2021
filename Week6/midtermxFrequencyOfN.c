#include <stdio.h>

int frequency(int array[], int n, int x);

int main()
{

    int number;
    int myArray[] = {2, 5, 1, 3, 3, 3, 3, 6, 3, 5, 3};
    
    number = frequency(myArray, 8, 3);

    printf("%i\n", number);

    return 0;
}

int frequency (int theArray [], int n, int x)
{
    int count = 0;      // increases for number of time n is in array
    int idx;            //index of array

    for (idx = 0; idx < n; ++idx)
    {
        if (theArray[idx] == x)
            {
                count += 1;
            }
    }

    return count;
}