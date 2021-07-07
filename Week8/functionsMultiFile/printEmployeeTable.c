#include <stdio.h>
#include "employee.h"

//******************************************************************************
// Function: prints the employee wage, hours, ot hours and gross pay
//
// parameters: clockNumber, hourlyWage, hoursWorked, overtimeHours, gross
//
// returns: none. prints the remainder of the table
//******************************************************************************
void printEmployeeTable(struct employees *pointer, int size)
{

    int idx;

    /* print out employee information */
    for (idx = 0; idx < size; ++idx)
    {

        printf("\t%06li %8.2f %6.1f %7.2f %12.2f\n",
               pointer->clockNumber, pointer->hourlyWage, pointer->hoursWorked,
               pointer->otHours, pointer->gross);

        ++pointer;
    }
}