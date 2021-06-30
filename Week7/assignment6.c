/*********************************************************/
//
// Homework: 6 - strings (Chapter 9)
//
// Name: Avery Bouchard
//
// Class: C Programming, Summer 2021
//
// Date: 6/28/2021
//
// Description: This program prompts the user for the number of hours
// worked for each employee. It then calculates gross pay
// including overtime and displays the results in table. Functions
// and structures are used.
//
//********************************************************/

#include <stdio.h>


//define global structure for employee

struct name
{
    char first[50];
    char middleInitial[3];
    char last [100];
};

struct employees
{
    struct name employeeName;
    long int clockNumber;
    float hourlyWage;
    float hoursWorked;
    float otHours;
    float gross;
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

char char_val;


int main()
{    

    struct employees employeeData[SIZE] = {     // initialize employee data (clockNumber and hourlyWage)
        {{"Connie", "A", "Cobol"}, 98401, 10.6},
        {{"Mary", "C", "Apl"}, 526488, 9.75},
        {{"Frank", "A", "Fortran"}, 765349, 10.5},
        {{"Jeff", "S", "Ada"}, 34645, 12.25},
        {{"Anton", "B", "Pascal"}, 127615, 8.35}
    }; 

    printf ("%c \n", char_val = 'a' + 6); 

    printf("%s\n\n", employeeData[1].employeeName.first);

    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n\n");

    //function calls in main function
    getHours(employeeData);

    calcOvertimeHours(employeeData);

    calcGrossPay(employeeData);

    printTableHeader();

    printEmployeeTable(employeeData);

    printf("\t____________________________________________________________________________\n");

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
        printf("Enter the number of hours %s %s worked: ", employeeData[idx].employeeName.first, employeeData[idx].employeeName.last);
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
    printf("\t__________________________________________________________________________\n\n");
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

        printf("\t%s, %5s %3s. \t%06li %13.2f \t%.2f %8.2f %10.2f\n", employeeData[idx].employeeName.last, employeeData[idx].employeeName.first, employeeData[idx].employeeName.middleInitial, employeeData[idx].clockNumber, employeeData[idx].hourlyWage, employeeData[idx].hoursWorked, employeeData[idx].otHours, employeeData[idx].gross);

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