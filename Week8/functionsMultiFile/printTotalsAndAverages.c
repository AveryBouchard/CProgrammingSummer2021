#include <stdio.h>
#include "employee.h"

//************************************************************************************
// Function: printTotalsAnd Averages
//
// Purpose: adds each element in the arrays for wage, hours, ot hours and gross pay
//              then divides by SIZE to determine averages
//
// Parameters: hourlyWage - the number of hours the employee worked
//             hoursWorked - hours worked input by the user in the getHours function
//             overtimeHours - the number of overtime hours the employee hoursWorked
//             gross - the gross pay the employee will recieve
//
// Returns: none - prints all totals and averages to the console
//**************************************************************************************
void printTotalsAndAverages(struct employees *pointer, int size)
{

    float wageTotal = 0;
    float hoursTotal = 0;
    float otTotal = 0;
    float grossTotal = 0;
    float wageAverage = 0;
    float hoursAverage = 0;
    float otAverage = 0;
    float grossAverage = 0;
    int idx;

    for (idx = 0; idx < size; ++idx)
    {

        wageTotal += pointer->hourlyWage;   /* add employee wage to all previous employees wages */
        hoursTotal += pointer->hoursWorked; /* add hours worked to total previous employees hours */
        otTotal += pointer->otHours;        /* add overtime hours to all previous employees */
        grossTotal += pointer->gross;       /* add gross pay to all previous employees */

        ++pointer;
    }

    wageAverage = wageTotal / size;
    hoursAverage = hoursTotal / size;
    otAverage = otTotal / size;
    grossAverage = grossTotal / size;

    printf("\n\tTotal %9.2f %6.1f %7.2f %12.2f\n", wageTotal, hoursTotal, otTotal, grossTotal);
    printf("\n\tAverage %7.2f %6.1f %7.2f %12.2f\n", wageAverage, hoursAverage, otAverage, grossAverage);
}