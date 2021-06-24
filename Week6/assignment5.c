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
//********************************************************/

#include <stdio.h>

struct employees
{
    long int clockNumber;
    float hourlyWage;
    float hoursWorked;
    float otHours;
    float gross;
};

// constants
#define SIZE (5)                /* Number of employees to process <-- change this for more or less employees*/
#define STANDARD_HOURS (40)     /* standard 40 hour work week */
#define OT_RATE (1.5)           /* multiply OT hours by this number */

// function prototypes
void getHours(struct employees employeeData[]);
void calcOvertimeHours(struct employees employeeData[]);
void printTableHeader();
void calcGrossPay(struct employees employeeData[]);
void printEmployeeTable(struct employees employeeData[]);
void printTotalsAndAverages(struct employees employeeData[]);

int main()
{    

    struct employees employeeData;
    {

        long int clockNumber [SIZE] = {98401, 526488, 765349, 34645, 127615};       /* employee clock number */
        float hourlyWage [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35};                  /* hourly wage */
        float hoursWorked[SIZE] = {};                                               /* number of hours worked per week */
        float otHours[SIZE] = {};                                                   /* calculated overtime hours worked */
        float gross[SIZE] = {};                                                     /* gross pay for week (wage * hours) */

    }
 
    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n\n");

    getHours(employeeData);

    calcOvertimeHours(employeeData);

    calcGrossPay(employeeData);

    printTableHeader();

    printEmployeeTable(employeeData);

    printf("\t_______________________________________________________\n");

    printTotalsAndAverages(employeeData);

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
void calcOvertimeHours(struct employees employeeData[])
{
    
    int idx; 

    for(idx = 0; idx < SIZE; ++idx)

        if (employeeData[idx].hoursWorked >= STANDARD_HOURS)
        {
            employeeData[idx].otHours = employeeData[idx].hoursWorked - STANDARD_HOURS;        
        }
        else{
            employeeData[idx].otHours = 0;
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
void calcGrossPay(struct employees employeeData[])
{
    int idx;

    for (idx = 0; idx < SIZE; ++idx)
    {
        employeeData[idx].gross = employeeData[idx].hourlyWage * (employeeData[idx].hoursWorked - employeeData[idx].otHours) + (employeeData[idx].otHours * OT_RATE * employeeData[idx].hourlyWage);
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
void printEmployeeTable(struct employees employeeData[])
{

    int idx;

    /* print out employee information */
    for (idx=0; idx < SIZE; ++idx){

        printf("\t%06li %8.2f %6.1f %7.2f %12.2f\n", employeeData[idx].clockNumber, employeeData[idx].hourlyWage, employeeData[idx].hoursWorked, employeeData[idx].overtimeHours, employeeData[idx].gross);

    }
}

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
void printTotalsAndAverages(struct employees employeeData[])
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

    for (idx = 0; idx < SIZE; ++idx){

        wageTotal += employeeData[idx].hourlyWage; /* add employee wage to all previous employees wages */
        hoursTotal += employeeData[idx].hoursWorked; /* add hours worked to total previous employees hours */
        otTotal += employeeData[idx].overtimeHours; /* add overtime hours to all previous employees */
        grossTotal += employeeData[idx].gross; /* add gross pay to all previous employees */

    }

    wageAverage = wageTotal/ SIZE;
    hoursAverage = hoursTotal / SIZE;
    otAverage = otTotal / SIZE;
    grossAverage = grossTotal / SIZE;

    printf("\n\tTotal %9.2f %6.1f %7.2f %12.2f\n", wageTotal, hoursTotal, otTotal, grossTotal);
    printf("\n\tAverage %7.2f %6.1f %7.2f %12.2f\n", wageAverage, hoursAverage, otAverage, grossAverage);

}