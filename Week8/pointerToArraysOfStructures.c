#include <stdio.h>

#define SIZE 3

//struct type for an employee
struct employee
{
    int id;
    float wage, hours;
};

//function prototypes
void getHours(struct employee *ptr, int size);
void printData(struct employee *ptr, int size);

/*********************************************************
* Function - getHours
*
* Description: Will prompt for the number of hours worked
* for each employee stored in the employee
* array being passed
*
* Parameters: ptr - pointer to an array of employees
* size - the number of employees to process
*
* Returns: void (the pointer will update the passed array)
*
**********************************************************/
void getHours(struct employee *ptr, int size)
{
    int i; //loop index

    for (i = 0; i < size; ++i)
    {
        printf("\nEnter employee hours for employee %06i: ", ptr->id);
        scanf("%f", &ptr->hours);

        //move pointer to next employee
        ++ptr;
    }
}

/********************************************************* 
* Function - printData
*
* Description: For a given set of employees, this function
* will print a one line summary report on each
* employee. The total number of employees
* printed is based on the size parameter.
*
* Parameters: ptr - pointer to an array of employees
* size - the number of employees to process
*
* Returns: void (the pointer will update the passed array)
*
**********************************************************/
void printData(struct employee *ptr, int size)
{
    int i; //loop index

    printf("\n\nID\tWage\tHours\n");

    for (i = 0; i < size; ++i)
    {
        printf("%06i\t%5.2f\t%5.1f\n",
               ptr->id,
               ptr->wage,
               ptr->hours);

        //move pointer to next employee
        ++ptr;
    }
}

int main()
{
    //array of structures
    struct employee emp[SIZE] = {
        {98401, 10.60},
        {526488, 9.75},
        {765349, 10.50}};

    //read in hours for each employee
    getHours(emp, SIZE);

    //print data information to the screen
    printData(emp, SIZE);

    return 0;
}