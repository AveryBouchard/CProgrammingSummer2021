#include <stdio.h>
#include "employee.h"

//******************************************************************************
// Function: prints the employee wage, hours, ot hours and gross pay
//
// parameters: clockNumber, hourlyWage, hoursWorked, overtimeHours, gross
//
// returns: none. prints the remainder of the table
//******************************************************************************
void printEmployeeTable(struct employees employeeData[])
{

    int idx;

    /* print out employee information */
    for (idx=0; idx < SIZE; ++idx){

        printf("\t%06li %8.2f %6.1f %7.2f %12.2f\n", employeeData[idx].clockNumber, employeeData[idx].hourlyWage, employeeData[idx].hoursWorked, employeeData[idx].otHours, employeeData[idx].gross);

    }
}