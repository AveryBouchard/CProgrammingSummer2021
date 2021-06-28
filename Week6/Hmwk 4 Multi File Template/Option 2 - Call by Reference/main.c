/* Add file comment block here per coding standards with your name */

#include <stdio.h>
#include "employees.h"


int main ()
{

    /* Variable Declarations */

    long  int clockNumber[NUM_EMPL] = {98401,526488,765349,34645,127615}; /* ID */
    float gross[NUM_EMPL];     /* gross pay */
    float hours[NUM_EMPL];     /* hours worked in a given week */
    float overtime[NUM_EMPL];  /* overtime hours */
    float wageRate[NUM_EMPL] = {10.60,9.75,10.50,12.25,8.35}; /* hourly wage rate */

    /* Function call to get hours worked for each employee */
    getHours (clockNumber, hours, NUM_EMPL);

    /* Function call to calculate overtime */

    /* Function call to calculate gross pay */

    /* Function call to output results to the screen */

    return (0);
}