#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct employee {
    int id;
    float wage;

    struct employee *next;
};

void printList (struct employee *emp1);

/*---------------------------------------------------------------
**
** FUNCTION: print_list
**
** DESCRIPTION: This function will print the contents of a linked
** list. It will traverse the list from beginning to the
** end, printing the contents at each node.
**
** PARAMETERS: emp1 - pointer to a linked list
**
** OUTPUTS: None
**
** CALLS: None
**
**---------------------------------------------------------------*/
void printList(struct employee *emp1)
{
    struct employee *tmp; //temp pointer
    int i = 0; //counts the nodes printed

    /*Start at beginning of list and print out each value */    
    /*loop until tmp points to null (0 or false) */
    for(tmp = emp1; tmp; tmp = tmp->next)
    {
        i++;
        printf("\nEmployee ID: %6i, Wage: %8.2f\n", tmp->id, tmp->wage);
    }

    printf("\n\nTotal Number of Employees = %d\n", i);
}    

/*-----------------------------------------------------------
**
** FUNCTION: main
**
** DESCRIPTION: This function will prompt the user for an
** employee id and wage until the user indicates they are
** finished. At that point, a list of id and wages will be
** generated.
**
** PARAMETERS: None
**
** OUTPUTS: None
**
** CALLS: print_list
**
**-----------------------------------------------------------*/
int main()
{
    char answer[80]; //holds user reply to prompt
    int idValue; //ID to search for 
    int moreData = 1; //flag to continue processing
    char value; //holds first character of user reply

    struct employee *currentPointer; //pointer to current node
    struct employee *headPointer; //pointer to first node

    //Set up storage for first node
    headPointer = (struct employee *) malloc (sizeof(struct employee));
    currentPointer = headPointer;

    while(moreData)
    {
        //Read in employee ID and hourly wage
        printf ("\n\nEnter employee ID: ");
        scanf("%i", & currentPointer -> id);

        printf ("\nEnter employee weekly wage: ");
        scanf("%f", &currentPointer -> wage);

        printf("\n\nWould you like to add another employee? (y/n): ");
        scanf("%s", answer);

        //add another employee?
        if ((value = toupper(answer[0])) != 'Y')
        {
            currentPointer -> next = (struct employee *) NULL;
            moreData = 0;
        }
        else
        {
            //create new node, set pointer to it
            currentPointer -> next = (struct employee *)malloc (sizeof(struct employee));

            //point to the new node
            currentPointer = currentPointer->next;
        } 


    } //while loop

    //print out current contents of linked list
    printList(headPointer);

    printf("\n\nEnd of Program\n");

    return (0);
}