#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>    /* for toupper */
#include "employees.h"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  print_list                                                       */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked             */
/*               list.  It will traverse the list from beginning to the        */
/*               end, printing the contents at each node.                      */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

void print_list(struct employee *emp1)
{
        struct employee *tmp;   /* tmp pointer value to current node */
        int i = 0;              /* counts the nodes printed          */

        /* Start a beginning of list and print out each value               */
        /* loop until tmp points to null (remember null is 0 or false)      */
        for(tmp = emp1; tmp ; tmp = tmp->next)
        {
            i++;

            /* TODO - print other members as well */
            printf("\nEmployee ID: %6d, Wage: %8.2f\n",tmp->id_number,
                                                      tmp->wage);
        }

        printf("\n\nTotal Number of Employees = %d\n", i);

}