#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>
 
#define OVERTIME_RATE 1.5
#define STD_WORK_WEEK 40

struct employee
     {
     char first_name [10];
     char last_name [10];
     long int id_number;
     float wage;
     float hours;
     float overtime;
     float gross;

     struct employee *next;
     };

/* TODO - Add Function Prototypes as needed -------------DONE */
void Output_Results_Screen (struct employee *pointer);
void get_Overtime (struct employee *pointer);
void get_Gross (struct employee *pointer);
void total_average_results (struct employee *pointer, int size);
void print_list (struct employee *pointer);
void printTableHeader();

/* TODO - Add Functions here as needed */
/* *******************************************************************
** Function: Output_Results_Screen
**
** Purpose: Outputs to screen in a table format the following
** information about an employee: Employee name, Clock ID, Wage,
** Hours, Overtime, and Gross Pay.
**
** Parameters:
**
**   employeeData - an array of structures containing
**   employee information
**   size - number of employees to process
**
** Returns: Nothing (void)
**
******************************************************************* */
 
void Output_Results_Screen (struct employee *pointer)  /*------------------DONE???????---------*/
{
	struct employee *tmp;   /* tmp pointer value to current node */
    int i = 0;              /* counts the nodes printed          */
 
    /* print information about each employee */
    for (tmp = pointer; tmp ; tmp = tmp->next)
    {
    	
        printf("\n %-15s %10s %6li\t%5.2f\t%4.1f\t%4.1f\t%8.2f",
        tmp -> first_name, tmp-> last_name, tmp -> id_number, tmp -> wage, tmp -> hours,
        tmp -> overtime, tmp -> gross);
        
        i++;
    } /* for */
	printf("\nNumber of employees: %i\n",i);
}

/* *******************************************************************
** Function: total_average_results
**
** Purpose: calculate totals and averages of horus worked
**
** Parameters:
**
**   employeeData - an array of structures containing
**   employee information
**   size - number of employees to process
**
** Returns: Nothing (void)
**
******************************************************************* */
 
void total_average_results ( struct employee *pointer, int size )
{
    float total_hours; /* total hours worked from all employees */
    float total_wage; /* total hourly rates for all employees */
    float total_ot; /* total overtime worked by all employees */
    float total_gross; /* total gross paid to all employees */
    float average_wage; /* average hourly rate for all employees */
    float average_hours; /* average hours worked by all employees */
    float average_ot; /* average overtime worked by all employees */
    float average_gross; /* average gross pay to all employees */
 
    struct employee *tmp;   /* tmp pointer value to current node */
    int i = 0;              /* counts the nodes printed          */
 
    for(tmp = pointer; tmp ; tmp = tmp->next)/* print information about each employee */
    
 
    {
	    total_wage += tmp -> wage; 
		total_hours += tmp -> hours;
		total_ot += tmp -> overtime;
		total_gross += tmp -> gross; 
 
		average_wage = total_wage/ size; /* calculation for average wage */
    	average_hours = total_hours / size; /* calculation for average hours */
    	average_ot = total_ot / size; /* calculation for average overtime hours */
    	average_gross = total_gross / size; /* calculation for average gross pay */
 
		tmp++;
 
    } /* for */
 
    printf("\nTotal:    \t\t\t\t%5.2f\t%4.1f\t%4.1f\t%8.2f", total_wage, total_hours, total_ot, total_gross);
    printf("\nAverage:  \t\t\t\t%5.2f\t%4.1f\t%4.1f\t%8.2f\n", average_wage, average_hours, average_ot, average_gross);
 
}
  
//**************************************************************/ 
// Function: get_Overtime
// 
// Purpose: to calculate overtime hours
// Parameters: hours - total hours worked in a week
//			   
// 
// Returns: the calculated amount of hours worked in a normal work week
//  
//**************************************************************/
 
void get_Overtime (struct employee *pointer)
{
    struct employee *tmp; //temporary pointer to current node

    for (tmp = pointer; tmp; tmp = tmp->next)
    {
        if (tmp->hours >= STD_WORK_WEEK)
        {
            tmp->overtime = tmp->hours - STD_WORK_WEEK;
        }
        else
        {
            tmp->overtime = 0;
        }
    }
}

//**************************************************************/ 
// Function: getGross 
// 
// Purpose: to calculate the gross pay 
// 
// Parameters: overtime- amount of hours worked over 40
//			   hours - total hours worked
//			   wage - normal hourly rate
//             
//             
//
// Returns: total gross pay for the work week
//  
//**************************************************************/
 
void get_Gross (struct employee *pointer)
{
 
    struct employee *tmp;
    
    for (tmp = pointer; tmp; tmp = tmp -> next)
    {
        /* if else statement to account for gross hours with or without overtime */
        if (tmp->overtime > 0) /* calculate gross pay taking into account for overtime */
        {   
            tmp->gross = (STD_WORK_WEEK * tmp->wage) + /* regular pay for hours within 40 hour work week */
                ((OVERTIME_RATE * tmp->wage) * tmp->overtime); /* additional hours with wage increased by constant multiplier */
        }
    
        else /* calculate gross pay of hours up to 40 */
        {
            tmp->gross = tmp->wage * tmp->hours;
        }
    }
}

//******************************************************************************
// Function: tableHeader
//
// Purpose:  prints table header
//
// parameters: 
//
// returns: 
//******************************************************************************
void printTableHeader()
{
    
    printf("\n\tEmployee name         | ID number       |  Wage | Hours | OT Hours | Gross\n");  /* Categories */
    printf("\t__________________________________________________________________________\n\n");
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  print_list                                                       */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked             */
/*               list.  It will traverse the list from beginning to the        */
/*               end, printing the contents at each node.                      */
/*                                                                             */
/* PARAMETERS:   *pointer - pointer to a linked list                               */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void print_list(struct employee *pointer)
{
        struct employee *tmp;   /* tmp pointer value to current node */
        int i = 0;              /* counts the nodes printed          */
 
        /* Start a beginning of list and print out each value               */
        /* loop until tmp points to null (remember null is 0 or false)      */
        for(tmp = pointer; tmp ; tmp = tmp->next)
        {
            i++;

            /* TODO - print other members as well ---------DONE*/  
            printf("\n %10s, %10s, %6li, %8.2f, %6.2f, %6.2f, %8.2f\n", tmp->first_name, tmp->last_name, tmp->id_number, tmp->wage, tmp->hours, tmp->overtime, tmp->gross);
            
        }
 
        printf("\n\nTotal Number of Employees = %d\n", i);
 
}
 
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* FUNCTION:  main                                                            */
/*                                                                            */
/* DESCRIPTION:  This function will prompt the user for an employee           */
/*               id and wage until the user indicates they are finished.      */
/*               At that point, a list of id and wages will be                */
/*               generated.                                                   */
/*                                                                            */
/* PARAMETERS:   None                                                         */
/*                                                                            */
/* OUTPUTS:      None                                                         */
/*                                                                            */
/* CALLS:        print_list                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int main ()
{
 
    char   answer[80];       /* to see if the user wants to add more employees */
    int    more_data = 1;    /* flag to check if another employee is to be processed */
    char   value;            /* gets the first character of answer */
	int size = 0;		/* number of employees */
    struct employee *current_ptr,   /* pointer to current node */
                    *head_ptr;      /* always points to first node */
 
   /* Set up storage for first node */
    head_ptr = (struct employee *) malloc (sizeof(struct employee));
    current_ptr = head_ptr;
 
    while (more_data)
    {
        

        /* TODO - Prompt for Employee Name and Hours as well here ------------DONE*/
        
		printf("\n Enter employee's first name: ");
		scanf("%s", &current_ptr-> first_name);
		
		printf("\n Enter employee's last name: ");
		scanf("%s", &current_ptr-> last_name);
		
       /* Read in Employee ID and Hourly Wage */
        printf("\n Enter employee ID: ");
        scanf("%li", &current_ptr -> id_number);
 
        printf("\n Enter employee hourly wage: ");
        scanf("%f", &current_ptr -> wage);
        
        printf("\n Enter employee's hours worked: ");
		scanf("%f", &current_ptr-> hours);

        /* TODO - Call Function(s) to calculate Overtime and Gross -------------DONE*/
        

        printf("Would you like to add another employee? (y/n): ");
        scanf("%s", answer);
 
        /* Ask user if they want to add another employee */
            if ((value = toupper(answer[0])) != 'Y')
        {
           current_ptr->next = (struct employee *) NULL;
           more_data = 0; 
        }
        else
        {
        	size++;
        	
           /* set the next pointer of the current node to point to the new node */
           current_ptr->next = (struct employee *) malloc (sizeof(struct employee));
          /* move the current node pointer to the new node */
           current_ptr = current_ptr->next;
           
         }
    } /* while */
    
    get_Overtime (head_ptr);
    
    get_Gross (head_ptr);
    
    printTableHeader();
    
    Output_Results_Screen (head_ptr);
   
    /* print out listing of all employee id's and wages that were entered */
    print_list(head_ptr);
    
    total_average_results(head_ptr, size);
    
 
    printf("\n\nEnd of program\n");
    return (0);
}