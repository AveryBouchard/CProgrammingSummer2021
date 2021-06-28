#include <stdio.h>
#include "employees.h"

//**************************************************************/
// Function: getHours
//
// Purpose: Obtains input from user, the number of hours worked
// per employee and stores the result in a local variable
// that is passed back to the calling function.
//
// Parameters: clockNumber - The clock number of the employee
//
// Returns: hoursWorked - hours worked by the employee in a given week
//
//**************************************************************/

float getHours (long int clockNumber)
{

    float hoursWorked; /* hours worked in a given week */

    /* Get Hours for each employee */
    printf("\nEnter hours worked by emp # %06li: ", clockNumber);
    scanf ("%f", &hoursWorked);

    return (hoursWorked);
}