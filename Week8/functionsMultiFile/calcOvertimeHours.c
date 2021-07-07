#include <stdio.h>
#include "employee.h"

//************************************************************************************
// Function: calcOvertimeHours
//
// Purpose: given the clock number and hours worked, function calculates whether there are
//              overtime hours and how many and saves in the array overtimeHours.
//
// Parameters: clockNumber - the clock number of the employee
//             hoursWorked - hours worked input by the user in the getHours function
//
// Returns: none - overtime hours are saved in the array overtimeHours
//**************************************************************************************
void calcOvertimeHours(struct employees *pointer, int size)
{

    int idx;

    for (idx = 0; idx < size; ++idx)
    {

        if (pointer->hoursWorked >= STANDARD_HOURS)
        {
            pointer->otHours = pointer->hoursWorked - STANDARD_HOURS;
        }
        else
        {
            pointer->otHours = 0;
        }

        ++pointer;
    }
}