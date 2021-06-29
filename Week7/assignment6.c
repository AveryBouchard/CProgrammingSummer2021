/*********************************************************/
//
// Homework: 6 - strings (Chapter )
//
// Name: Avery Bouchard
//
// Class: C Programming, Summer 2021
//
// Date: 6/21/2021
//
// Description: This program prompts the user for the number of hours
// worked for each employee. It then calculates gross pay
// including overtime and displays the results in table. Functions
// and structures are used.
//
//********************************************************/

#include <stdio.h>
#include <string.h>


//define global structure for employee

struct name
{
    char first[50];
    char middleInitial[3];
    char last [100];
};

struct employees
{
    long int clockNumber;
    float hourlyWage;
    float hoursWorked;
    float otHours;
    float gross;
    struct name employeeName;
};

// global constants
#define SIZE (5)                /* Number of employees to process <-- change this for more or less employees*/
#define STANDARD_HOURS (40)     /* standard 40 hour work week */
#define OT_RATE (1.5)           /* multiply OT hours by this number */

// function prototypes
void getHours(struct employees employeeData[]);
void calcOvertimeHours(struct employees employeeData[]);
void printTableHeader();                                                    // we can pass the employee structure as a parameter to each function
void calcGrossPay(struct employees employeeData[]);                         // instead of passing each variable individually
void printEmployeeTable(struct employees employeeData[]);
void printTotalsAndAverages(struct employees employeeData[]);


struct name employeeName[SIZE] = {
    {"Connie", "A", "Courderoy"},
    {"Kobi", "C", "McLoberton"},
    {"Courtney", "A", "Coughlin"},
    {"Avery", "S", "Bouchard"},
    {"Stella", "B", "Bella"}
};

int main()
{    

    struct employees employeeData[SIZE] = {     // initialize employee data (clockNumber and hourlyWage)
        { 98401, 10.6},
        { 526488, 9.75},
        { 765349, 10.5},
        { 34645, 12.25},
        { 127615, 8.35}
    }; 

    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n\n");

    //function calls in main function
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
        printf("Enter the number of hours employee %s %s worked: ", employeeName[idx].first, employeeName[idx].last);
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
    printf("\n\tEmployee Name         | Clock#       |  Wage | Hours | OT Hours | Gross\n");
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

        printf("\t%s, %s %s. \t%06li \t%13.2f \t%.1f %8.2f %10.2f\n", employeeName[idx].last, employeeName[idx].first, employeeName[idx].middleInitial, employeeData[idx].clockNumber, employeeData[idx].hourlyWage, employeeData[idx].hoursWorked, employeeData[idx].otHours, employeeData[idx].gross);

    }
struct name employeeName[SIZE] = {
    {"Connie", "A", "Courderoy"},
    {"Kobi", "C", "McLobe"},
    {"Courtney", "A", "Coughlin"},
    {"Avery", "S", "Bouchard"},
    {"Stella", "B", "Bella"}
};
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
    float minHours = employeeData[0].hoursWorked;
    float minOvertime = employeeData[0].otHours;
    float minGross = employeeData[0].gross;
    float maxHours = 0;
    float maxOvertime = 0;
    float maxGross = 0;
    int idx;

    for (idx = 0; idx < SIZE; ++idx){

        wageTotal += employeeData[idx].hourlyWage; /* add employee wage to all previous employees wages */
        hoursTotal += employeeData[idx].hoursWorked; /* add hours worked to total previous employees hours */
        otTotal += employeeData[idx].otHours; /* add overtime hours to all previous employees */
        grossTotal += employeeData[idx].gross; /* add gross pay to all previous employees */

        if (employeeData[idx].hoursWorked < minHours)
            minHours = employeeData[idx].hoursWorked;

        if (employeeData[idx].otHours < minOvertime)
            minOvertime = employeeData[idx].otHours;

        if (employeeData[idx].gross < minGross)
            minGross = employeeData[idx].gross;

        if (employeeData[idx].hoursWorked > maxHours)
            maxHours = employeeData[idx].hoursWorked;

        if (employeeData[idx].otHours > maxOvertime)
            maxOvertime = employeeData[idx].otHours;

        if (employeeData[idx].gross > maxGross)
            maxGross = employeeData[idx].gross;

    }

    wageAverage = wageTotal/ SIZE;
    hoursAverage = hoursTotal / SIZE;
    otAverage = otTotal / SIZE;
    grossAverage = grossTotal / SIZE;

    printf("\n\tTotal \t\t\t\t%13.2f %7.1f %8.2f %10.2f", wageTotal, hoursTotal, otTotal, grossTotal);
    printf("\n\tAverage \t\t\t\t%5.2f %7.1f %8.2f %10.2f\n", wageAverage, hoursAverage, otAverage, grossAverage);
    printf("\n\tMaximums:\t\t\t\t\t%.2f %8.2f %10.2f", maxHours, maxOvertime, maxGross);
    printf("\n\tMinimums:\t\t\t\t\t%.2f %8.2f %10.2f", minHours, minOvertime, minGross);

}

void minimum()
{
    int idx;

}