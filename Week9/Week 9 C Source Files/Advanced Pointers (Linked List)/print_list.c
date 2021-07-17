#include <stdio.h>
#include "employees.h"

/*---------------------------------------------------------------
**
** FUNCTION: print_list
**
** DESCRIPTION: This function will print the contents of a linked
**    list. It will traverse the list from beginning to the
**    end, printing the contents at each node.
**
** PARAMETERS: emp1 - pointer to a linked list
**
** OUTPUTS: None
**
** CALLS: None
**
**---------------------------------------------------------------*/

void print_list (struct employee *emp1)
{
    struct employee *tmp; /* tmp pointer */
    int i = 0;            /* counts the nodes printed */

    /* Start a beginning of list and print out each value */
    /* loop until tmp points to null (0 or false) */
    for(tmp = emp1; tmp ; tmp = tmp->next)
    {
        i++;
        printf("\nEmployee ID: %6i, Wage: %8.2f\n",tmp->id, tmp->wage);

    }

    printf("\n\nTotal Number of Employees = %d\n", i);

}