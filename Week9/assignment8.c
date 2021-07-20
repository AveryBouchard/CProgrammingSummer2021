/*********************************************************/
//
// Homework: 8 - Linked Lists
//
// Name: Avery Bouchard
//
// Class: C Programming, Summer 2021
//
// Date: 7/17/2021
//
// Description: This program prompts the user for the number of hours
// worked for each employee. It then calculates gross pay
// including overtime and displays the results in table. Functions
// and structures are used.
//
//********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//define global structure for employee

struct name
{
    char first[50];
    char middleInitial[3];
    char last[100];
};

struct employee
{
    struct name employeeName;
    long int clockNumber;
    float hourlyWage;
    float hoursWorked;
    float otHours;
    float gross;

    struct employee *next;
};

// global constants
#define STANDARD_HOURS 40 /* standard 40 hour work week */
#define OT_RATE 1.5       /* multiply OT hours by this number */

// function prototypes
void getHours(struct employee *pointer);
void calcOvertimeHours(struct employee *pointer);
void printTableHeader();                     
void calcGrossPay(struct employee *pointer); 
void printEmployeeTable(struct employee *pointer);
void printTotalsAndAverages(struct employee *pointer, int count);

int main()
{

    char answer[80];  //to see if user wants to add additional employee
    int moreData = 1; //flag to check if another employee is to be processed
    char value;       //gets first character of the answer
    int count = 0;    //count of number of employees

    struct employee *currentPointer, //pointer to current node
        *headPointer;                //always points to first node

    //set up storage of first node
    headPointer = (struct employee *)malloc(sizeof(struct employee));
    currentPointer = headPointer;

    printf("This is a program to calculate gross pay.\n");
    printf("You will be prompted for employee data.\n\n");

    //get employee data (possibly get this in it's own function?)
    while (moreData)
    {
        //Prompt for employee name
        printf("Enter Employee First Name: ");
        scanf("%s", &currentPointer->employeeName.first);
        printf("Enter Employee Middle Initial: ");
        scanf("%s", &currentPointer->employeeName.middleInitial);
        printf("Enter Employee Last Name: ");
        scanf("%s", &currentPointer->employeeName.last);

        //Prompt for employee ID:
        printf("Enter Employee ID Number: ");
        scanf("%li", &currentPointer->clockNumber);

        //Prompt for hourly wage
        printf("Enter Hourly Wage: ");
        scanf("%f", &currentPointer->hourlyWage);

        //Prompt for hours worked
        printf("Enter Hours Worked: ");
        scanf("%f", &currentPointer->hoursWorked);

        //ask user to add another employee
        printf("Would you like to add another employee? (y/n): ");
        scanf("%s", answer);

        if ((value = toupper(answer[0])) != 'Y')
        {
            currentPointer->next = (struct employee *)NULL;
            moreData = 0;
        }
        else
        {
            count++;
            //set the next pointer of the current node to point to the new node
            currentPointer->next = (struct employee *)malloc(sizeof(struct employee));
            //move current node pointer to the new node
            currentPointer = currentPointer->next;
        }
    }

    printTableHeader();

    calcGrossPay(headPointer);

    calcOvertimeHours(headPointer);

    printEmployeeTable(headPointer);

    printf("\t____________________________________________________________________________\n");

    printTotalsAndAverages(headPointer, count);

    printf("\n\n");

    return (0);

} /* main function */

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
void calcOvertimeHours(struct employee *pointer)
{

    struct employee *temp; //temporary pointer to current node

    for (temp = pointer; temp; temp = temp->next)
    {

        if (temp->hoursWorked >= STANDARD_HOURS)
        {
            temp->otHours = temp->hoursWorked - STANDARD_HOURS;
        }
        else
        {
            temp->otHours = 0;
        }
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
// Returns: none - gross pay is saved in gross
//**************************************************************************************
void calcGrossPay(struct employee *pointer)
{
    struct employee *temp; //temporary pointer to current node

    for (temp = pointer; temp; temp = temp->next)
    {
        temp->gross = temp->hourlyWage * (temp->hoursWorked - temp->otHours) + (temp->otHours * OT_RATE * temp->hourlyWage);
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
void printEmployeeTable(struct employee *pointer)
{

    int idx = 0;           //counts the nodes printed
    struct employee *temp; //temporary pointer value to current node

    /* print out employee information */
    for (temp = pointer; temp; temp = temp = temp->next)
    {

        idx++;

        printf("\t%s, %5s %3s. \t%06li %13.2f \t%.2f %8.2f %10.2f\n",
               temp->employeeName.last, temp->employeeName.first,
               temp->employeeName.middleInitial, temp->clockNumber,
               temp->hourlyWage, temp->hoursWorked, temp->otHours,
               temp->gross);
    }

    printf("\n\nTotal Number of Employees: %i\n", idx);
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
void printTotalsAndAverages(struct employee *pointer, int count) // pass by reference
{

    struct employee *temp; //temporary pointer value to current node

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

    for (temp = pointer; temp; temp = temp->next)
    {
        wageTotal += temp->hourlyWage;   /* add employee wage to all previous employee wages */
        hoursTotal += temp->hoursWorked; /* add hours worked to total previous employee hours */
        otTotal += temp->otHours;        /* add overtime hours to all previous employee */
        grossTotal += temp->gross;       /* add gross pay to all previous employee */

        if (temp->hoursWorked < minHours)
            minHours = temp->hoursWorked;

        if (temp->otHours < minOvertime)
            minOvertime = temp->otHours;

        if (temp->gross < minGross)
            minGross = temp->gross;

        if (temp->hoursWorked > maxHours)
            maxHours = temp->hoursWorked;

        if (temp->otHours > maxOvertime)
            maxOvertime = temp->otHours;

        if (temp->gross > maxGross)
            maxGross = temp->gross;
    }

    wageAverage = wageTotal / count;
    hoursAverage = hoursTotal / count;
    otAverage = otTotal / count;
    grossAverage = grossTotal / count;

    printf("\n\tTotal \t\t\t\t%13.2f %7.1f %8.2f %10.2f", wageTotal, hoursTotal, otTotal, grossTotal);
    printf("\n\tAverage \t\t\t\t%5.2f %7.1f %8.2f %10.2f\n", wageAverage, hoursAverage, otAverage, grossAverage);
    printf("\n\tMaximums:\t\t\t\t\t%.2f %8.2f %10.2f", maxHours, maxOvertime, maxGross);
    printf("\n\tMinimums:\t\t\t\t\t%.2f %8.2f %10.2f", minHours, minOvertime, minGross);
}