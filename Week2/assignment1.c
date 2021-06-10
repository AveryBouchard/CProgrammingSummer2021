/*********************************************************/
//
// Homework: 1 (Chapter 4/5)
//
// Name: Avery Bouchard
//
// Class: C Programming, Summer 2021
//
// Date: 5/29/2021
//
// Description: Program which determines gross pay
//
//
//********************************************************/

#include <stdio.h>

int main()
{
    /* initialize variables */
    int clockNumber;        /* employee clock number */
    float gross;            /* gross pay for week (wage * hours) */
    float hoursWorked;      /* number of hours worked per week */
    float hourlyWage;       /* hourly wage */
    int idx;                /* loop index */
    int employeesToProcess; /* how many employees will need to be processed? */

    /* prompt for number of employees that will need to be processed */
    printf("Enter the number of employees to process:\n");
    scanf("%i", &employeesToProcess);

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

        /* calculate gross pay */
        gross = hourlyWage * hoursWorked;

        /* print out employee information */
        printf("\n\tClock # Wage Hours Gross\n");
        printf("\t______________________________________________________\n\n");
        printf("\t%06i %5.2f %5.1f %7.2f\n\n\n", clockNumber, hourlyWage, hoursWorked, gross);
    }

    return (0);

} /* main function */