/*********************************************************/
//
// Homework: 4 (Chapter 8)
//
// Name: Avery Bouchard
//
// Class: C Programming, Summer 2021
//
// Date: 6/9/2021
//
// Description: Program which determines gross pay
//
//
//********************************************************/

#include <stdio.h>

int main()
#define SIZE (5)
{
    /* initialize variables */
    float gross;            /* gross pay for week (wage * hours) */
    float hoursWorked;    /* number of hours worked per week */
    int idx;                /* loop index */
    float overtimeHours;
    const float standardHours = 40; /* standard 40 hour work week */
    const float otRate = 1.5; /* multiply OT hours by this number */
    const int employeesToProcess = 5; /* how many employees will need to be processed? */
    long int clockNumber [SIZE] = {98401, 526488, 765349, 34645, 127615}; /* employee clock number */
    float hourlyWage [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35}; /* hourly wage */

    /* begin for loop */
    for (idx = 0; idx < employeesToProcess; idx++)
    {

        /* prompt for input values */
        printf("This is a program to calculate gross pay.\n");
        printf("You will be prompted for employee data.\n\n");
        printf("Enter the number of hours employee %li worked: ", clockNumber[idx]);
        scanf("%f", &hoursWorked);

        if (hoursWorked >= standardHours)
        {
            overtimeHours = hoursWorked - standardHours;        
        }
        else{
            overtimeHours = 0;
        }

        /* calculate gross pay */
        gross = hourlyWage[idx] * (hoursWorked - overtimeHours) + overtimeHours * otRate;


        /* print out employee information */
        printf("\n\tClock # | Wage | Hours | OT Hours | Gross\n");
        printf("\t______________________________________________________\n\n");
        printf("\t%06li %8.2f %6.1f %7.2f %12.2f\n\n\n", clockNumber[idx], hourlyWage[idx], hoursWorked, overtimeHours, gross);
    }

    return (0);

} /* main function */