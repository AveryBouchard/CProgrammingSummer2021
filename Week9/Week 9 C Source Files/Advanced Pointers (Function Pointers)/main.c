#include <stdio.h>

/* function prototypes */
int sum (int num1, int num2);

int main ()
{
    /* Second, define a pointer to a function which */
    /* receives 2 integer values and returns an int */
    int ( *functionPtr ) (int, int);

    /* point to address (note the &) of our sum function */
    functionPtr = &sum;

    /* Finally, let's actually use our function pointer */
    int mySum = (*functionPtr)(5, 10); /* the sum is 15 */

    printf ("mySum calculated by the function pointer is %i \n", mySum);

    return (0);

}