/*  GLOBAL, AUTO, and STATIC VARIABLE DECLARATION EXAMPLE */

#include <stdio.h>

int globalvar = 2;  /* global variable initialized only once */
                    /* and its value is always held in memory*/

/* function prototype */
void printit ();

int main ()
{

    int x;    /* local variable within main */

    /* Time line 1 */

    /* Call printit function three times */
    printit();
    printit();
    printit();

    x = 5;

    /* Time Line 3 */
    return(0);

} /* main */