#include <stdio.h>
#include "employees.h"

/********************************************************
** Function:  nextDay
**
** Description:  Returns the next day given a date
**
** Parameters:  dateval - a given date
**
** Returns:     dateval - updated next day date
**
*********************************************************/
struct date nextDay (struct date dateval)
{
    ++dateval.day;   /* add a day */

    return (dateval); /* return updated structure */

} /* nextDay */