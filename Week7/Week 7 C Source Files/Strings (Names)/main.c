#include <stdio.h>
#include "employees.h"

int main ()
{
    /* Store all employee names */
    struct employee names [SIZE] =
    {
        { "Connie", "Cobol" },
        { "Mary", "Apl" },
        { "Frank", "Fortran" },
        { "Jeff", "Ada" },
        { "Anton", "Pascal" } /* no comma here */
    };

    /* print all the employee names */
    printNames ( names );

    return (0);
}