/* Program to Test simple call to a function */

#include <stdio.h>

/* function prototyeps */
void pointerTest (int * int_ptr);

int main ()
{

    int myValue = 50;    /* simple integer value to test */

    int *ptr = &myValue; /* ptr is a pointer to an integer */
                             /* set to address of myValue      */

    printf ("Before function call:  myValue = %i and *ptr = %i \n", myValue, *ptr);

    /* call the function and pass the contents of the pointer ptr, */
    /* which contains the ADDRESS of the variable myValue          */
    pointerTest ( ptr );

    /* upon return from test, the variable i will now be set to 100 */
    printf ("After function call:  myValue = %i and *ptr = %i \n", myValue, *ptr);

    return (0);
}