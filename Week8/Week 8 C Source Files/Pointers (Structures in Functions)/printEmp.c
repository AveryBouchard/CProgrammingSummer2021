#include <stdio.h>
#include "employees.h"

/*********************************************************************
* Function:  printEmp
*
* Description:  Prints information contained in an employee structure
*               given a pointer that has been set to it.
*
* Parameters:  emp_ptr - Pointer to the employee structure variale
*
* Returns:  void
*
**********************************************************************/
void printEmp (struct employee * emp_ptr)
{

    /* print a nice header */
    printf ("\nClock  Wage   Hours ");

    /* print the contents of the employee structure variable */
    /* using the pointer to the employee structure variable  */
    printf ("\n%06i %5.2f %5.1f\n", emp_ptr->id_number,
                            emp_ptr->wage,
                    emp_ptr->hours);
    return;
}