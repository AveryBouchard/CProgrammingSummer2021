#include <stdio.h>
#include "employees.h"

/***************************************************************
**
** Name: printNames
**
** Description: Prints the first and last names in an array
**
** Parameters: myNames - Array of Structures containing names
**
** Returns: Nothing
**
****************************************************************/

void printNames (struct employee myNames [ ] )
{
    int i; /* loop index */

    /* Print first name and then last name */
    for (i = 0; i < SIZE; ++i)
    {
        printf ("%s %s \n", myNames [ i ].first_name,
                myNames [ i ].last_name);
    }

} /* printNames */