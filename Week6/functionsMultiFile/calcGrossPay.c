#include <stdio.h>
#include "employee.h"

//************************************************************************************
// Function: calcGrossPay
//
// Purpose: given the clock number, hours worked and ovetime hours, function calculates 
//              the total amount of pay.
//
// Parameters: clockNumber - the clock number of the employee
//             hoursWorked - hours worked input by the user in the getHours function
//             overtimeHours - amount of overtime worked from calcOvertimeHours function
//
// Returns: none - gross pay is saved in the array gross
//**************************************************************************************
void calcGrossPay(struct employees employeeData[])
{
    int idx;

    for (idx = 0; idx < SIZE; ++idx)
    {
        employeeData[idx].gross = employeeData[idx].hourlyWage * (employeeData[idx].hoursWorked - employeeData[idx].otHours) + (employeeData[idx].otHours * OT_RATE * employeeData[idx].hourlyWage);
    }
}