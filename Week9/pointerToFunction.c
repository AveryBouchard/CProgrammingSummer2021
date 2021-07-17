#include <stdio.h>

/*******************************************
**
** Function: test
**
** Description - Demonstrates how a pointer is passed
** to a function. The pointer will update
** a value it is referencing in the Calling Function.
**
** Parameters: int_ptr - a pointer to an integer
**
** Returns: void
**
********************************************/
void test(int *intPointer) //address passed into the pointer parameter
{
    *intPointer = 100; // 2
}

int main()
{
    int value = 50, *pointer = &value; // 1
    
    test (pointer); //pass the contents of pointer

    printf ("value = %i \n", value); //value will now be 100

    return(0);
}