#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Types
struct employee
{
    int id;
    float wage;
    struct employee *next; //pointer to next node
};

// function prototypes
struct employee * findEntry (struct employee * listPointer, int idNumber);
void printList (struct employee *emp1);

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
int main()
{
    char answer[80]; //holds user reply to prompt
    int idValue; //ID to search for
    int moreData = 1; //flag to continue processing
    char value; //holds first character of user reply

    struct employee *currentPointer; //pointer to current node
    struct employee *headPointer; //pointer to first node

    //set up storage for first node
    headPointer =(struct employee *) malloc (sizeof(struct employee));
    currentPointer = headPointer;

    while(moreData)
    {
        //read in employee ID and hourly wage
        printf ("\n\nEnter employee ID: ");
        scanf("%i", & currentPointer -> id);

        printf ("\nEnter employee weekly wage: ");
        scanf("%f", & currentPointer -> wage);

        printf("\n\nWould you like to add another employee? (y/n): ");
        scanf("%s", answer);

        //add another employee
        if((value = toupper(answer[0])) != 'Y')
        {
            currentPointer -> next = (struct employee *) NULL;
            moreData = 0;
        }
        else
        {
            //create new node, set pointer to it
            currentPointer -> next = (struct employee *) malloc (sizeof(struct employee));

            //point to the new node
            currentPointer = currentPointer->next;
        }
    } //while

    //print out current contents of linked list
    printList(headPointer);

    printf("Enter an ID to search for in our list: ");
    scanf("%i", &idValue);

    //search for ID
    if (findEntry (headPointer, idValue) != (struct employee *) NULL)
    {
        printf("\n\nID is in the list\n");
    }
    else
    {
        printf("\n\nID is not in the list\n");
    }

    printf("\n\nEnd of Program\n");

    return(0);
}

/***********************************************************************************
**
** Function: findEntry
**
** Description: Using list_ptr as a starting point, examine every entry in
** the list until an entry is found that has an id_number which
** matches the one passed to the function. If found, return a pointer
** to the node, otherwise, return NULL.
**
** Parameters: list_ptr - pointer to the beginning of the link list
**     id_number - employee identifier to search
**
** Returns: Pointer to linked list node with the ID (otherwise NULL returned)
**
************************************************************************************/
 struct employee * findEntry (struct employee * listPointer, int idNumber)
 {
     struct employee * foundItPointer = listPointer; //set to beginning of list

     //search through linked list, return a pointer to the node if ID found
     for ( ; foundItPointer; foundItPointer = foundItPointer -> next)
     {
         if (foundItPointer -> id == idNumber)
            return (foundItPointer); //Found
     }

     return ( (struct employee *) NULL); //not found, return NULL pointer
 } //find entry

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
void printList (struct employee *emp1)
{
    struct employee *tmp; //temp pointer
    int i; //counts the nodes printed

    //start at beginning of list and print out each value
    //loop until tmp points to null (0 or false)
    for(tmp = emp1; tmp; tmp = tmp -> next)
    {
        i++;
        printf("\nEmployee ID: %6i, Wage: %8.2f\n", tmp->id, tmp->wage);
    }

    printf("\n\nTotal Number of Employees = %d\n", i);
}