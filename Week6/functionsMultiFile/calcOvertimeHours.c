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
void calcOvertimeHours(struct employees employeeData[])
{
    
    int idx; 

    for(idx = 0; idx < SIZE; ++idx)

        if (employeeData[idx].hoursWorked >= STANDARD_HOURS)
        {
            employeeData[idx].otHours = employeeData[idx].hoursWorked - STANDARD_HOURS;        
        }
        else{
            employeeData[idx].otHours = 0;
        }
}