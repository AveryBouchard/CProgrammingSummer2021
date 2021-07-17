#include <stdio.h>

//global variables
int x = 10;
int y = 20;


/**********************************************
Function: noUpdatePointer

Description: Receives a pointer and updates it.
    However, the contents of the pointer, while 
    changed in this function, remain unchanged
    in the calling function.
    This shows that pointers are passed BY VALUE.

Parameters: pointer - a pointer to an integer

Returns: void
***********************************************/
void noUpdatePointer(int *pointer)
{
    pointer = &y; //no change to pointer in main
}

/***********************************************
Function: update Pointer

Description: Receives a pointer to a pointer and uses it
    to update the contents of the pointer it is referencing.
    The result is that the pointer will be updated in the
    calling function.

    Pass pointers to pointers to functions to change the
    contents of the pointers they are pointing to in both
    the called AND calling functions.

Parameters: pointer - a pointer to a pointer that points
    to an int

Returns: void
***************************************************/
void updatePointer (int **pointer)
{
    *pointer = &y; //this will actually change pointer in main
}


/**************************************************
Function: someFunc

Description: Receives a simple int, a float pointer,
    and an int pointer. Shows that only pointer vars
    will update corresponding items they are pointing 
    to in the calling function.

Parameters: a - simple int value
            b - pointer to a float
            c - pointer to an int

Returns: void
***************************************************/
void someFunc(int a, float *b, int *c)
{
    a = 1;
    *b = 2.2;
    *c = 3;
}

int main()
{
    int a, c, *pointer; //2 int and an int pointer
    float b; //float variable
    pointer = &x; //points to global int variable x

    a = 0;
    b = 0;
    c = 0;

    someFunc(a, &b, &c); //call to see what changes upon return

    //Note that only b and c were updated, not a
    printf("a = %d, b = %f, c = %d\n", a, b, c);

    printf("before calls, *pointer = %d\n", *pointer);

    noUpdatePointer(pointer); //nothing changes to what pointer points to

    printf(" *pointer = %d after call to noUpdatePointer \n", *pointer);

    updatePointer(&pointer); //passing address of the pointer can change pointer on return

    printf(" *pointer = %d after call to updatePointer\n", *pointer);

    return(0);

}