#include <stdio.h>
#include "employees.h"

/*********************************************************
* Function - printData
*
* Description: For a given set of employees, this function
* will print a one line summary report on each
* employee. The total number of employees
* printed is based on the size parameter.
*
* Parameters: ptr - pointer to an array of employees
* size - the number of employees to process
*
* Returns: void (the pointer will update the passed array)
*
    **********************************************************/

void printData (struct employee * ptr, int size)
{
    int i; /* loop index */

    printf ("\n\nID     Wage   Hours\n");

    for (i = 0; i < size; ++i)
    {
        printf ("%06i %5.2f %5.1f\n", ptr->id, ptr->wage, ptr->hours);

        /* move pointer to next employee */
        ++ptr;
    }
}