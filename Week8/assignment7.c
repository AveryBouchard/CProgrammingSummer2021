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
#include <time.h>

//define global structure for employee

struct name
{
    char first[50];
    char middleInitial[3];
    char last[100];
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
#define SIZE 5            /* Number of employees to process <-- change this for more or less employees*/
#define STANDARD_HOURS 40 /* standard 40 hour work week */
#define OT_RATE 1.5       /* multiply OT hours by this number */

// function prototypes
void getHours(struct employees *pointer, int size);
void calcOvertimeHours(struct employees *pointer, int size);
void printTableHeader();                                // we can pass the employee structure as a parameter to each function
void calcGrossPay(struct employees *pointer, int size); // instead of passing each variable individually
void printEmployeeTable(struct employees *pointer, int size);
void printTotalsAndAverages(struct employees *pointer, int size);

int main()
{

    clock_t begin = clock();

    struct employees employeeData[SIZE] = {// initialize employee data (clockNumber and hourlyWage)
                                           {{"Connie", "A", "Cobol"}, 98401, 10.6},
                                           {{"Mary", "C", "Apl"}, 526488, 9.75},
                                           {{"Frank", "A", "Fortran"}, 765349, 10.5},
                                           {{"Jeff", "S", "Ada"}, 34645, 12.25},
                                           {{"Anton", "B", "Pascal"}, 127615, 8.35}};

    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n\n");

    //function calls in main function
    getHours(employeeData, SIZE);

    calcOvertimeHours(employeeData, SIZE);

    calcGrossPay(employeeData, SIZE);

    printTableHeader();

    printEmployeeTable(employeeData, SIZE);

    printf("\t____________________________________________________________________________\n");

    printTotalsAndAverages(employeeData, SIZE);

    printf("\n\n");

    clock_t end = clock();

    int time_spent = (int)(end - begin);

    printf("\n\nTime Spent (pointers): %i \n\n", time_spent);


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
void getHours(struct employees *pointer, int size)
{

    int idx; //loop index

    for (idx = 0; idx < size; ++idx)
    {
        /* prompt for input values */
        printf("Enter the number of hours %s %s worked: ", pointer->employeeName.first, pointer->employeeName.last);
        scanf("%f", &pointer->hoursWorked);

        ++pointer;
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
void calcOvertimeHours(struct employees *pointer, int size)
{

    int idx;

    for (idx = 0; idx < size; ++idx)
    {

        if (pointer->hoursWorked >= STANDARD_HOURS)
        {
            pointer->otHours = pointer->hoursWorked - STANDARD_HOURS;
        }
        else
        {
            pointer->otHours = 0;
        }

        //move pointer to next employee
        ++pointer;
    }
}
//************************************************************************************
// Function: calcGrossPay
//
// Purpose: given the clock number, hours worked and overtime hours, function calculates
//              the total amount of pay.
//
// Parameters: clockNumber - the clock number of the employee
//             hoursWorked - hours worked input by the user in the getHours function
//             overtimeHours - amount of overtime worked from calcOvertimeHours function
//
// Returns: none - gross pay is saved in the array gross
//**************************************************************************************
void calcGrossPay(struct employees *pointer, int size)
{
    int idx;

    for (idx = 0; idx < size; ++idx)
    {
        pointer->gross = pointer->hourlyWage * (pointer->hoursWorked - pointer->otHours) + (pointer->otHours * OT_RATE * pointer->hourlyWage);

        ++pointer;
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
void printEmployeeTable(struct employees *pointer, int size)
{

    int idx;

    /* print out employee information */
    for (idx = 0; idx < size; ++idx)
    {
        printf("\t%s, %5s %3s. \t%06li %13.2f \t%.2f %8.2f %10.2f\n",
               pointer->employeeName.last, pointer->employeeName.first,
               pointer->employeeName.middleInitial, pointer->clockNumber,
               pointer->hourlyWage, pointer->hoursWorked, pointer->otHours,
               pointer->gross);

        ++pointer;
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
//             gross - the gross pay the employee will receive
//
// Returns: none - prints all totals and averages to the console
//**************************************************************************************
void printTotalsAndAverages(struct employees *pointer, int size) // pass by reference
{

    float wageTotal = 0;
    float hoursTotal = 0;
    float otTotal = 0;
    float grossTotal = 0;
    float wageAverage = 0;
    float hoursAverage = 0;
    float otAverage = 0;
    float grossAverage = 0;
    float minHours = pointer->hoursWorked;
    float minOvertime = pointer->otHours;
    float minGross = pointer->gross;
    float maxHours = 0;
    float maxOvertime = 0;
    float maxGross = 0;
    int idx;

    for (idx = 0; idx < SIZE; ++idx)
    {

        wageTotal += pointer->hourlyWage;   /* add employee wage to all previous employees wages */
        hoursTotal += pointer->hoursWorked; /* add hours worked to total previous employees hours */
        otTotal += pointer->otHours;        /* add overtime hours to all previous employees */
        grossTotal += pointer->gross;       /* add gross pay to all previous employees */

        if (pointer->hoursWorked < minHours)
            minHours = pointer->hoursWorked;

        if (pointer->otHours < minOvertime)
            minOvertime = pointer->otHours;

        if (pointer->gross < minGross)
            minGross = pointer->gross;

        if (pointer->hoursWorked > maxHours)
            maxHours = pointer->hoursWorked;

        if (pointer->otHours > maxOvertime)
            maxOvertime = pointer->otHours;

        if (pointer->gross > maxGross)
            maxGross = pointer->gross;

        ++pointer;
    }

    wageAverage = wageTotal / SIZE;
    hoursAverage = hoursTotal / SIZE;
    otAverage = otTotal / SIZE;
    grossAverage = grossTotal / SIZE;

    printf("\n\tTotal \t\t\t\t%13.2f %7.1f %8.2f %10.2f", wageTotal, hoursTotal, otTotal, grossTotal);
    printf("\n\tAverage \t\t\t\t%5.2f %7.1f %8.2f %10.2f\n", wageAverage, hoursAverage, otAverage, grossAverage);
    printf("\n\tMaximums:\t\t\t\t\t%.2f %8.2f %10.2f", maxHours, maxOvertime, maxGross);
    printf("\n\tMinimums:\t\t\t\t\t%.2f %8.2f %10.2f", minHours, minOvertime, minGross);
}
