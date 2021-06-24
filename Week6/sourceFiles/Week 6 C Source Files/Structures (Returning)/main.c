#include <stdio.h>
#include "employees.h"

int main ()
{

    /* two structure variables */
    struct date today, tomorrow;

    /* set today to the proper date */
    today.day = 17;
    today.year = 1996;
    today.month = 10;

    /* This statement illustrates the ability to pass a  */
    /* structure to a function and to return one as well */

    tomorrow = nextDay (today); /* tomorrow updated */

    printf ("%d/%d/%d\n", tomorrow.month,
                          tomorrow.day,
                          tomorrow.year-1900);

    return (0);
}