#include <stdio.h> //for print, scan
#include <stdlib.h> //for malloc()
#include <ctype.h> //for toupper()

struct employee
{
    int id_number;
    float wage;

    struct employee *next;
};

/**********************************************************
Function - print_list

Description - print the contents of a linked list. It
                will traverse the list from beginning
                to the end, printing the contents at
                each node.

Parameters - emp1 - pointer to a linked list

Outputs - None

Calls - None
***********************************************************/
void print_list(struct employee *emp1)
{

    struct employee *tmp; //tmp pointer value to current node
    int i = 0; //counts the nodes printed

    //start at beginning of list and print out each value 
    //loop until tmp points to null
    for(tmp = emp1; tmp; tmp = tmp->next)
    {

        i++;
        printf("\nEmployee ID: %6d, Wage: %8.2f\n",tmp->id_number,
                                                    tmp->wage);

    }

    printf("\n\nTotal Number of Employees: %d\n", i);
}

/*Function - main

Description - prompt the user for an employee id and wage until the user 
                indicates they are finished. At that point, a list of id 
                and wages will be generated.

Parameters - None


Outputs - None

Calls - print_list()*/

int main()
{
    char answer[80]; //to see if user wants to add more employees
    int more_data = 1; //flag to check if another employee is to be processed
    char value; //gets first character of answer

    struct employee *current_ptr, //pointer to current node
                    *head_ptr;     //always points to first node

    //set up storage for first node
    head_ptr = (struct employee *) malloc (sizeof(struct employee));
    current_ptr = head_ptr;

    while(more_data)
    {
        //read in employee ID and wage
        printf("Employee ID: ");
        scanf("%i", &current_ptr->id_number);

        printf("Hourly Wage: ");
        scanf("%f", &current_ptr->wage);

        printf("Would you like to enter another employee? (y/n): ");
        scanf("%s", answer);

        //ask user if they want to enter another employee
        if ((value = toupper(answer[0])) != 'Y')
        {
            current_ptr -> next = (struct employee *) NULL;
            more_data = 0;
        }
        else
        {
            //set next pointer of the current node to point to the new node
            current_ptr -> next = (struct employee *) malloc (sizeof(struct employee));
            //move current node pointer to the new node
            current_ptr = current_ptr -> next;
        }
    } //while loop

    //print out listing of all employee IDs and wages that were entered
    print_list(head_ptr);

    printf("\n\nEnd of Program\n\n");

    return(0);

}