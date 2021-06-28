#include <stdio.h>
#include "employees.h"

//**************************************************************/
// Function: getHours
//
// Purpose: Obtains input from user, the number of hours worked
// per employee and stores the results in an array that is
// passed back to the calling function by reference.
//
// Parameters:
//
// emp_num - Array of employee clock numbers for each employee
// hrs - Array of hours worked by each employee
// size - Number of employees to process
//
// Returns: Nothing (call by reference)
//
//**************************************************************/

void getHours (long emp_num[], float emp_hrs[], int size)
{

    int count; /* loop counter */

    /* Get Hours for each employee */
    for (count = 0; count < size; ++count)
    {
        printf("\nEnter hours worked by emp # %06li: ", emp_num[count]);
        scanf ("%f", &emp_hrs[count]);
    }

    printf("\n\n");
}