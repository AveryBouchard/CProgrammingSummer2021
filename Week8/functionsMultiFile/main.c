#include <stdio.h>
#include "employee.h"

int main()
{

    struct employees employeeData[SIZE] =
        {// initialize employee data (clockNumber and hourlyWage)
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

    printf("\t_______________________________________________________\n");

    printTotalsAndAverages(employeeData, SIZE);

    printf("\n\n");

    return (0);

} /* main function */