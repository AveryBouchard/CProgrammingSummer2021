#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "employees.h"

/*-----------------------------------------------------------
**
** FUNCTION: main
**
** DESCRIPTION: This function will prompt the user for an
**    employee id and wage until the user indicates they are
**    finished. At that point, a list of id and wages will be
**    generated.
**
** PARAMETERS: None
**
** OUTPUTS: None
**
** CALLS: print_list
**
**-----------------------------------------------------------*/

int main ()
{

    char answer[80];   /* holds user reply to prompt */
    int id_value;      /* ID to search for */
    int more_data = 1; /* flag to continue processing */
    char value;        /* holds first character of user reply */

    struct employee *current_ptr; /* pointer to current node*/
    struct employee *head_ptr;    /* points to first node */

    /* Set up storage for first node */
    head_ptr = (struct employee *) malloc (sizeof(struct employee));
    current_ptr = head_ptr;

    while (more_data)
    {

        /* Read in Employee ID and Hourly Wage */
        printf("\n\nEnter employee ID: ");
        scanf("%i", & current_ptr -> id);

        printf("\nEnter employee weekly wage: ");
        scanf("%f", & current_ptr -> wage);

        printf("\n\nWould you like to add another employee? (y/n): ");
        scanf("%s", answer);

        /* add another employee? */
        if ((value = toupper(answer[0])) != 'Y')
        {
            current_ptr->next = (struct employee *) NULL;
            more_data = 0;
        }
        else
        {
            /* create new node, set next pointer to it */
            current_ptr->next = (struct employee *) malloc (sizeof(struct employee));

            /* point to the new node */
            current_ptr = current_ptr->next;
        }
    } /* while */

    /* print out current contents of linked list */
    print_list(head_ptr);

    /* Enter an ID to search for in our list */
    printf ("Enter an ID to search for in our list: ");
    scanf ("%i", &id_value);

    /* Search for it */
    if (findEntry (head_ptr, id_value) != (struct employee *) NULL)
    {
        printf ("ID is in the list \n");
    }
    else /* NULL Ptr returned */
    {
        printf ("ID is NOT in the list \n");
    }

    printf("\n\nEnd of program\n");

    return (0);
}