#include <stdio.h>

int main()
{

    int *intPointer; //pointer to an int
    int **pointerPointer; //pointer to pointer that points to int
    int int2, int1 = 25; //simple int values to point to

    intPointer = &int1; //sets intPointer to point to an int
    pointerPointer = &intPointer; //sets pointerPointer to point to the pointer intPointer

    printf("int1 = %d\n", int1); //access variable int1 directly
    printf(" *intPointer = %d\n", *intPointer); //access value indirectly through intPointer
    printf(" **pointerPointer = %d\n", **pointerPointer); //access same value through pointerPointer

    //pointerPointer is of type pointer to pointer to int. Applying the indirection operation
    //to this expression (*pointerPointer) results in one of type pointer to int

    //Applying it once again (**pointerPointer) yields an expression of type int

    **pointerPointer = 50; //same as saying: *intPointer = 50; or int1 = 50

    intPointer = &int2; //if you wanted intPointer to point to int2
    *pointerPointer = &int2; //change address of intPointer indirectly through pointerPointer

    *intPointer = 100; //change int2 to 100 indirectly using pointer
    **pointerPointer = 200; //change int2 to 200 indirectly by pointerPointer

    printf("\nThe final values of all variables:\n\n");

    printf("int1 = %d\n", int1); //access variable int1 directly
    printf("int2 = %d\n", int2); //access variable int2 directly
    printf(" *intPointer = %d\n", *intPointer); //access int2 indirectly through intPointer
    printf(" **pointerPointer = %d\n", **pointerPointer); //access value indirectly through pointerPointer

    return(0);
}