#include <stdio.h>
#include "employees.h"

int main ()
{
    struct date today; /* local variable to main */

    /* Set up a date to pass to the printNextDay function */
    today.day = 17;
    today.year = 1996;
    today.month = 10;

    /* pass by value the information to our function*/
    printNextDay (today);

    /* The value of today will be unchanged - still the 17th */
    printf ("%d/%d/%d \n", today.month, today.day, today.year-1900);


    return (0);

} /* main */