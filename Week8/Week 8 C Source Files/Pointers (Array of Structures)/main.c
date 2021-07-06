#include <stdio.h>
#include "employees.h"

/* program to process employees using pointers */
/* to an array of structures                   */

int main ()
{

    /* Set up our Array of Structures and intialize it */
    struct employee emp [SIZE] = { {98401, 10.60},
                                   {526488, 9.75},
                                   {765349, 10.50}
                                 };

    /* Read in hours for each employee */
    getHours (emp, SIZE);

    /* Print employee information to the screen */
    printData (emp, SIZE);

    return (0);

}