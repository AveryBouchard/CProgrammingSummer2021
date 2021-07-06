#include <stdio.h>
#include "employees.h"

/*********************************************************
* Function - getHours
*
* Description: Will prompt for the number of hours worked
* for each employee stored in the employee
* array being passed
*
* Parameters: ptr - pointer to an array of employees
* size - the number of employees to process
*
* Returns: void (the pointer will update the passed array)
*
**********************************************************/

void getHours (struct employee * ptr, int size)
{
    int i; /* loop index */

    for (i = 0; i < size; ++i)
    {
        printf ("\nEnter hours for employee %06i: ", ptr->id);
        scanf ("%f", &ptr -> hours);

        /* move pointer to next employee */
        ++ptr;
    } /* for */

} /* getHours */