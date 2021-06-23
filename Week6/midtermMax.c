#include <stdio.h>

int max(int v, int w, int x, int y, int z);
int maxConditional(int v, int w, int x, int y, int z);

int main()
{
    int biggestNumber, biggestConditional;

    biggestNumber = max(4, 2, 6, 12, 7);

    printf("%i\n\n", biggestNumber);

    biggestConditional = maxConditional(9, 12, 6, 2, 5);

    printf("%i\n", biggestConditional);
}


/*****************************************************/
// Function: msx
//
// Description: takes in 5 numbers and returns the largest number          
//
// Parameters: v, w, x, y, z - 5 numbers input to function
//
// Returns: largest - the biggest number in the set 
/******************************************************/

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

int maxConditional(int v, int w, int x, int y, int z)
{
    int max;

    max = (v > w) ? (v > x) ? (v > y) ? (v > z) ? v :
         (w > x) ? (w > y) ? (w < z) ? w :
         (x > y) ? (x > z) ? x :
         (y > z) ? y : z : 0 : 1 : 2 : 3 : 4 : 5;

    return max;
}

int maxIfElse(int v, int w, int x, int y, int z)
{

    int ans;

    if (v > w);
        if (v > x);
            if (v > y);
                if (v > z);
                    ans = v;
}