#include <stdio.h>

struct employee
{
    int id;
    float wage, hours;
};

/************************************************************************************
* Function:  updateEmp
*
* Description:  Updates an employee using a pointer to a structure
*
* Parameters:  emp_ptr - Pointer to the employee structure variable
*              clock - employee clock number value
*              wage - employee weekly wage value
*              hours - employee hours worked value
*
* Returns:  void (but note the structure pointed to will be updated)
*
**************************************************************************************/
void updateEmp(struct employee *empPointer, int clock, float wage, float hours)
{
    //update employee using the passed pointer to the structure variable
    empPointer->id = clock;
    empPointer->wage = wage;
    empPointer->hours = hours;

    return;
}

void printEmp(struct employee *empPointer)
{
    //print a nice header
    printf("\n Clock    Wage    Hours");

    //print the contents of the employee structure variable using the pointer to
    //the employee structure variable
    printf("\n%06i %5.2f %5.1f\n", empPointer->id,
           empPointer->wage,
           empPointer->hours);

    return;
}

//program using pointer to a structure
int main()
{
    struct employee emp;     //structure
    struct employee *empPtr; //pointer to structure

    empPtr = &emp; //pointer to address of structure

    // (*empPtr).id = 98401; //can be done like this but....

    empPtr->id = 98401; //best way to do this

    //access and set the other 2 members too
    empPtr->wage = 10.60;
    empPtr->hours = 0;

    //print the employee
    printf("\nEmployee changed in main function by our pointer:\n");
    printEmp(empPtr);

    //update employee via a function call
    updateEmp(empPtr, 58734, 14.56, 40.0);

    //print the updated employee
    printf("\nEmployee updated in updateEmp function by our pointer:\n");
    printEmp(empPtr);

    return 0;
}