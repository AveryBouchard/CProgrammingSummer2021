#include <stdio.h>
#include "employee.h"

int main()
{    

    struct employees employeeData[SIZE] = {     // initialize employee data (clockNumber and hourlyWage)
        {98401, 10.6},
        {526488, 9.75},
        {765349, 10.5},
        {34645, 12.25},
        {127615, 8.35}
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