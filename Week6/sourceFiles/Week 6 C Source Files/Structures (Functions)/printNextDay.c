#include <stdio.h>
#include "employees.h"

/**************************************************************************
**
** Function: printNextDay
**
** Description: Simply prints the next day of a given 20th century date
** in MM/DD/YYYY format. Does not check for last day in the month (known
** issue to be addressed in the future)
**
** Parameters: dataval - a structure with month, day, and year
**
** Returns: void
**
**********************************************************************/

void printNextDay (struct date dateval)
{

    ++dateval.day; /* add a day to the value passed into this function */

    printf ("%d/%d/%d\n", dateval.month, dateval.day, dateval.year-1900);

    return; /* optional, no value returned since it returns void */

} /* printNextDay */