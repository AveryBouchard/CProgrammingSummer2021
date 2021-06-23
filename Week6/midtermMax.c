#include <stdio.h>

int max(int v, int w, int x, int y, int z);

int main()
{
    int biggestNumber;

    biggestNumber = max(4, 2, 6, 12, 7);

    printf("%i\n\n", biggestNumber);
}

int max (int v, int w, int x, int y, int z)
{
    int largest = 0;
    int array[5] = {v, w, x, y, z};
    int idx;

    for (idx = 0; idx < 5; ++idx)
    {
        if (array[idx] > largest)
            largest = array[idx];
    }

    return largest;
      
}