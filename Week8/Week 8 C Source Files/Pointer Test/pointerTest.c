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
void pointerTest (int * int_ptr)
{
    *int_ptr = 100; /* set the contents of the address it points
                       to to 100, which in this case, is where
                       variable i in the main routine is located */
}