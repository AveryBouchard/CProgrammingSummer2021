/*********************************************************/
//
// Homework: 3 (Chapter 8)
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
    const int standardHours = 40; /* standard 40 hour work week */
    const float otRate = 1.5; /* multiply OT hours by this number */
    const int employeesToProcess = 5; /* how many employees will need to be processed? */
    int idx;                /* loop index */

    /* initialize variables to calculate totals and averages */
    float wageTotal;
    float wageAverage;
    float hoursTotal; 
    float hoursAverage;
    float otTotal;
    float otAverage;
    float grossTotal;
    float grossAverage;
    
    /* initialize arrays */
    float gross[SIZE] = {};            /* gross pay for week (wage * hours) */
    float hoursWorked[SIZE] = {};    /* number of hours worked per week */
    float overtimeHours[SIZE] = {}; 
    long int clockNumber [SIZE] = {98401, 526488, 765349, 34645, 127615}; /* employee clock number */
    float hourlyWage [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35}; /* hourly wage */

    
    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n\n");

    /* begin for loop */
    for (idx = 0; idx < employeesToProcess; idx++)
    {

        /* prompt for input values */
        printf("Enter the number of hours employee %li worked: ", clockNumber[idx]);
        scanf("%f", &hoursWorked[idx]);

        if (hoursWorked[idx] >= standardHours)
        {
            overtimeHours[idx] = hoursWorked[idx] - standardHours;        
        }
        else{
            overtimeHours[idx] = 0;
        }

        /* calculate gross pay */
        gross[idx] = hourlyWage[idx] * (hoursWorked[idx] - overtimeHours[idx]) + overtimeHours[idx] * otRate;

        /* calculate totals */
        wageTotal += hourlyWage[idx]; /* add employee wage to all previous employees wages */
        hoursTotal += hoursWorked[idx]; /* add hours worked to total previous employees hours */
        otTotal += overtimeHours[idx]; /* add overtime hours to all previous employees */
        grossTotal += gross[idx]; /* add gross pay to all previous employees */

    }

    /* calculate averages */
    wageAverage = wageTotal / SIZE;
    hoursAverage = hoursTotal / SIZE;
    otAverage = otTotal / SIZE;
    grossAverage = grossTotal / SIZE;


    /* start of table */
    printf("\n\tClock # | Wage | Hours | OT Hours | Gross\n");
    printf("\t______________________________________________________\n\n");

    /* print out employee information */
    for (idx=0; idx < SIZE; ++idx){

        printf("\t%06li %8.2f %6.1f %7.2f %12.2f\n", clockNumber[idx], hourlyWage[idx], hoursWorked[idx], overtimeHours[idx], gross[idx]);

    }

    printf("\t_______________________________________________________\n");

    /* print totals */
    printf("\n\tTotal %9.2f %6.1f %7.2f %12.2f\n", wageTotal, hoursTotal, otTotal, grossTotal);

    /* print averages */
    printf("\tAverage %7.2f %6.1f %7.2f %12.2f\n", wageAverage, hoursAverage, otAverage, grossAverage);

    printf("\n\n");

    return (0);

} /* main function */