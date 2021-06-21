
/*********************************************************/
//
// Homework: 4 (Chapter 7)
//
// Name: Avery Bouchard
//
// Class: C Programming, Summer 2021
//
// Date: 6/21/2021
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
void getHours(long int clockNumber[], float hoursWorked[]);
void calcOvertimeHours(float hoursWorked[], float overtimeHours[]);
void printTableHeader();
void calcGrossPay(float hourlyWage[], float hoursWorked[], float overtimeHours[], float gross[]);
void printEmployeeTable(long int clockNumber[], float hourlyWage[], float hoursWorked[], float overtimeHours[], float gross[]);
void printTotals(float hourlyWage[], float hoursWorked[], float overtimeHours[], float gross[]);

int main()
{    
    /* initialize arrays */
    float gross[SIZE] = {};            /* gross pay for week (wage * hours) */
    float hoursWorked[SIZE] = {};    /* number of hours worked per week */
    float overtimeHours[SIZE] = {}; 
    long int clockNumber [SIZE] = {98401, 526488, 765349, 34645, 127615}; /* employee clock number */
    float hourlyWage [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35}; /* hourly wage */

    
    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n\n");

    getHours(clockNumber, hoursWorked);

    calcOvertimeHours(hoursWorked, overtimeHours);

    calcGrossPay(hourlyWage, hoursWorked, overtimeHours, gross);

    printTableHeader();

    printEmployeeTable(clockNumber, hourlyWage, hoursWorked, overtimeHours, gross);

    printf("\t_______________________________________________________\n");

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
void getHours(long int clockNumber[], float hoursWorked[])
{

    int idx;

    for(idx = 0; idx < SIZE; ++idx){
    /* prompt for input values */
        printf("Enter the number of hours employee %li worked: ", clockNumber[idx]);
        scanf("%f", &hoursWorked[idx]);
    }
    printf("\n\n");

}


//************************************************************************************
// Function: calcOvertimeHours
//
// Purpose: given the clock number and hours worked, function calculates whether there are
//              overtime hours and how many and saves in the array overtimeHours.
//
// Parameters: clockNumber - the clock number of the employee
//             hoursWorked - hours worked input by the user in the getHours function
//
// Returns: none - overtime hours are saved in the array overtimeHours
//**************************************************************************************
void calcOvertimeHours(float hoursWorked[], float overtimeHours[])
{
    
    int idx; 

    for(idx = 0; idx < SIZE; ++idx)

        if (hoursWorked[idx] >= STANDARD_HOURS)
        {
            overtimeHours[idx] = hoursWorked[idx] - STANDARD_HOURS;        
        }
        else{
            overtimeHours[idx] = 0;
        }
}


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
void calcGrossPay(float hourlyWage[], float hoursWorked[], float overtimeHours[], float gross[])
{
    int idx;

    for (idx = 0; idx < SIZE; ++idx)
    {
        gross[idx] = hourlyWage[idx] * (hoursWorked[idx] - overtimeHours[idx]) + (overtimeHours[idx] * OT_RATE * hourlyWage[idx]);
    }
}


//******************************************************************************
// Function: printTableHeader
//
// Purpose: prints the header of the table. can be printed on every page of a stub
//
// parameters: none
//
// returns: none. simply prints table header.
//******************************************************************************
void printTableHeader()
{
    /* start of table */
    printf("\n\tClock # | Wage | Hours | OT Hours | Gross\n");
    printf("\t______________________________________________________\n\n");
}


//******************************************************************************
// Function: prints the employee wage, hours, ot hours and gross pay
//
// parameters: clockNumber, hourlyWage, hoursWorked, overtimeHours, gross
//
// returns: none. prints the remainder of the table
//******************************************************************************
void printEmployeeTable(long int clockNumber[], float hourlyWage[], float hoursWorked[], float overtimeHours[], float gross[])
{

    int idx;

    /* print out employee information */
    for (idx=0; idx < SIZE; ++idx){

        printf("\t%06li %8.2f %6.1f %7.2f %12.2f\n", clockNumber[idx], hourlyWage[idx], hoursWorked[idx], overtimeHours[idx], gross[idx]);

    }
}

void printTotals(float hourlyWage[], float hoursWorked[], float overtimeHours[], float gross[])
{

    float wageTotal, hoursTotal, otTotal, grossTotal;
    int idx;

    for (idx = 0; idx < SIZE; ++idx){

        wageTotal += hourlyWage[idx]; /* add employee wage to all previous employees wages */
        hoursTotal += hoursWorked[idx]; /* add hours worked to total previous employees hours */
        otTotal += overtimeHours[idx]; /* add overtime hours to all previous employees */
        grossTotal += gross[idx]; /* add gross pay to all previous employees */

    }

    printf("\n\tTotal %9.2f %6.1f %7.2f %12.2f\n", wageTotal, hoursTotal, otTotal, grossTotal);

}