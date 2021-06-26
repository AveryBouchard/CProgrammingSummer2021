#include <stdio.h>

int main()
{
    long int answer = 0;

    int x_to_the_n(int x, int n);

    answer = x_to_the_n(3, 10);

    printf("%li\n\n", answer);

    return 0;
}


//**************************************************
// Function: x_to_the_n
//
// Description: takes in 2 numbers, x and n and returns the result, 
//                  x to the power of n
//
// Parameters: x, n
//
// Returns: result - the result of x to the power of n.
//**************************************************
int x_to_the_n(int x, int n)
{
    int idx;
    long int result = x;

    for (idx = 0; idx < n-1; ++idx)
    {
        result *= x;
    }

    return result;
}