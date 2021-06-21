
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

// constants
#define SIZE (5) /* Number of employees to process <-- change this for more or less employees*/
#define STANDARD_HOURS (40) /* standard 40 hour work week */
#define OT_RATE (1.5) /* multiply OT hours by this number */

// function prototypes
void getHours(long int clockNumber[], float hoursWorked[], int size);
float calcOvertimeHours(long int, int);

int main()
{
    /* initialize variables */
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
    for (idx = 0; idx < SIZE; idx++)
    {
        calcOvertimeHours(clockNumber[idx], SIZE);

        /* calculate gross pay */
        gross[idx] = hourlyWage[idx] * (hoursWorked[idx] - overtimeHours[idx]) + (overtimeHours[idx] * OT_RATE  * hourlyWage[idx]);

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
void getHours(long int clockNumber[], float hoursWorked, int size)
{

    int idx;

    for(idx = 0; idx < idx; ++idx)
    /* prompt for input values */
        printf("Enter the number of hours employee %li worked: ", clockNumber[idx]);
        scanf("%f", &hoursWorked[idx]);

    printf("\n\n");

}

// float calcOvertimeHours(long int clockNumber, int size)
// {
    
//     float hoursWorked, overtimeHours;

//     hoursWorked = getHours(clockNumber);

//     if (hoursWorked >= STANDARD_HOURS)
//     {
//         overtimeHours = hoursWorked - STANDARD_HOURS;        
//     }
//     else{
//         overtimeHours = 0;
//     }

//     return overtimeHours;
// }