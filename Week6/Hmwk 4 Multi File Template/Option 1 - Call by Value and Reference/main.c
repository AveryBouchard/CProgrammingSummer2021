/* Add file comment block here per coding standards with your name */

#include <stdio.h>
#include "employees.h"

int main ()
{

    /* Variable Declarations */

    long  int clockNumber[NUM_EMPL] = {98401,526488,765349,34645,127615}; /* ID */
    float gross[NUM_EMPL];     /* gross pay */
    float hours[NUM_EMPL];     /* hours worked in a given week */
    int   i;                   /* loop and array index */
    float overtime[NUM_EMPL];  /* overtime hours */
    float wageRate[NUM_EMPL] = {10.60,9.75,10.50,12.25,8.35}; /* hourly wage rate */

    for (i = 0; i < NUM_EMPL; ++i)
    {

        /* Function call to get input from user. */
        hours[i] = getHours (clockNumber[i]);

        /* Function call to calculate overtime */

        /* Function call to calculate gross pay */

    }

    /* Print the header info */

    /* Print all the employees - call by reference */
    printEmp  (clockNumber, wageRate, hours,
               overtime, gross, NUM_EMPL);

    return (0);
}