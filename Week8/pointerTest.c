/*********************************************************************
 * Function:  pointerTest
 *
 * Description:  Demos passing a pointer to a function as a parameter
 *               and changing the value referenced by that pointer will
 *               actually update the same variable value being
 *               referenced by a pointer in the calling function. 
 *   
 * Parameters:  int_ptr - Pointer to an int (to value in calling funct)
 *
 * Returns:  void (but value in calling function will be set to 100
 *
**********************************************************************/

#include <stdio.h>

void pointerTest(int *intPointer)
{
    *intPointer = 100; //set the contents of the address it points to to 100,
                       //which in this case, is where variable i in the main routine
                       //is located.
}

int main()
{
    int myValue = 50; //simple integer value to test

    int *ptr = &myValue; // ptr is set to an integer set to address of myValue

    printf("Before function call: myValue = %i and *ptr = %i \n",
           myValue, *ptr);

    //call the funtion and pass the contents of the pointer to ptr,
    //which contains the address of myValue
    pointerTest(ptr);

    //upon return from test, the variable i will now be set to 100
    printf("After function call: myValue = %i and *ptr = %i \n",
           myValue, *ptr);

    return 0;
}