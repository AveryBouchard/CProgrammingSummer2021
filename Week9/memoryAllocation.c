#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* types */
struct employee
{
    int id;
    float wage;
    struct employee *next;
};

/* function prototypes */
void print_list (struct employee *emp1);

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

    printf("\n\nEnd of program\n");

    return (0);
}

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