#include <stdio.h>
#include "employee.h"

//************************************************************************************
// Function: getHours
//
// Purpose: get input from user, the number of hours worked per employee and stores the result in the
//              local variable called hoursWorked, that is passed to the calling function.
//
// Parameters: clockNumber - the clock number of the employee
//
// Returns: hoursWorked - the number of hours worked for the given employee
//**************************************************************************************
void getHours(struct employees employeeData[])
{

    int idx;

    for(idx = 0; idx < SIZE; ++idx){
    /* prompt for input values */
        printf("Enter the number of hours employee %li worked: ", employeeData[idx].clockNumber);
        scanf("%f", &employeeData[idx].hoursWorked);
    }
    printf("\n\n");

}