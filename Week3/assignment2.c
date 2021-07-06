/*********************************************************/
//
// Homework: 2 (Chapter 4/5)
//
// Name: Avery Bouchard
//
// Class: C Programming, Summer 2021
//
// Date: 6/1/2021
//
// Description: Program which determines gross pay
//
//
//********************************************************/

#include <stdio.h>

int main()
{
    /* initialize variables */
    int clockNumber;   /* employee clock number */
    float gross;       /* gross pay for week (wage * hours) */
    float hoursWorked; /* number of hours worked per week */
    float hourlyWage;  /* hourly wage */
    int idx;           /* loop index */
    float overtimeHours;
    const float standadHours = 40;    /* standard 40 hour work week */
    const float otRate = 1.5;         /* multiply OT hours by this number */
    const int employeesToProcess = 5; /* how many employees will need to be processed? */

    // /* prompt for number of employees that will need to be processed */
    // printf("Enter the number of employees to process:\n");
    // scanf("%i", &employeesToProcess);

    /* begin for loop */
    for (idx = 1; idx <= employeesToProcess; idx++)
    {

        /* prompt for input values */
        printf("This is a program to calculate gross pay.\n");
        printf("You will be prompted for employee data.\n\n");
        printf("Enter clock number for employee %i: ", idx);
        scanf("%d", &clockNumber);
        printf("Enter hourly wage for employee %i (%i): ", idx, clockNumber);
        scanf("%f", &hourlyWage);
        printf("Enter the number of hours employee %i (%i) worked: ", idx, clockNumber);
        scanf("%f", &hoursWorked);

        if (hoursWorked >= standadHours)
        {
            overtimeHours = hoursWorked - standadHours;
        }
        else
        {
            overtimeHours = 0;
        }

        /* calculate gross pay */
        gross = hourlyWage * (hoursWorked - overtimeHours) + overtimeHours * otRate;

        /* print out employee information */
        printf("\n\tClock # | Wage | Hours | OT Hours | Gross\n");
        printf("\t______________________________________________________\n\n");
        printf("\t%06i %8.2f %6.1f %7.2f %12.2f\n\n\n", clockNumber, hourlyWage, hoursWorked, overtimeHours, gross);
    }

    return (0);

} /* main function */