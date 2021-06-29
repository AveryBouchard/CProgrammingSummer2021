/*********************************************************************
**
** HOMEWORK: #5 Structures
**
** Name: Nathan Goldrick
**
** Class: C Programming
**
** Date: 6/27/21
**
** Description: This program prompts the user for the number of hours
** worked for each employee. It then calculates gross pay
** including overtime and displays the results in table. Functions
** and structures are used.
**
/**********************************************************************/
 
/*Define and Includes */
 
#include <string.h>
 
/* Define Constants */
#define NUM_EMPL 5
#define OVERTIME_RATE 1.5
#define STD_WORK_WEEK 40.0
 
/* Define a global structure to pass employee data between functions */
/* Note that the structure type is global, but you don't want a variable */
/* of that type to be global. Best to declare a variable of that type */
/* in a function like main or another function and pass as needed. */
 
 struct employee
    {
      char  name [20];
      long  id_number;
      float wage;
      float hours;
      float overtime;
      float gross;
    };
 
/* define prototypes here for each function except main */
 
void Output_Results_Screen (struct employee employeeData [], int size);
void calculate_Overtime (struct employee employeeData [ ], int size);
void get_Gross (struct employee employeeData [ ], int size);
void total_average_results (struct employee employeeData [ ], int size);
 
/* add your functions here */
 
/* *******************************************************************
** Function: Output_Results_Screen
**
** Purpose: Outputs to screen in a table format the following
** information about an employee: Clock, Wage,
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
 
void Output_Results_Screen ( struct employee employeeData[], int size )
{
    int i; /* loop index */
 
    /* print information about each employee */
    for (i = 0; i < size ; ++i)
    {
        printf("\n %s %06li %5.2f %4.1f %4.1f %8.2f \n",
       employeeData[i].name, employeeData[i].id_number, employeeData[i].wage, employeeData[i].hours,
        employeeData[i].overtime, employeeData[i].gross);
    } /* for */
 
}
 
/* *******************************************************************
** Function: total_average_results
**
** Purpose: totals and averages of horus worked
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
 
void total_average_results ( struct employee employeeData[], int size )
{
    float wage;
    float hours;
    float overtime;
    float gross;
    float total_wage;
    float total_hours;
    float total_ot;
    float total_gross;
 
    int i; /* loop index */
 
    /* print information about each employee */
    for (i = 0; i < size ; ++i)
    {
	    total_wage += employeeData[i].wage;
		total_hours += employeeData[i].hours;
		total_ot += employeeData[i].overtime;
		total_gross += employeeData[i].gross; 
 
    } /* for */
 
    printf("\nTotal: %25.2f %10.1f %10.2f %10.2f", total_wage, total_hours, total_ot, total_gross);
    //printf("\nAverage: %25.2f %10.1f %10.2f %10.2f\n", ? , ? , ? , ? );
 
 
 
}
 
//**************************************************************/ 
// Function: getHours 
// 
// Purpose: Obtains input from user, the number of hours worked 
// per employee and stores the result in an local variable 
// that is passed back to the calling function. 
// 
// Parameters: clockNumber - The clock number of the employee
// 
// Returns: hoursWorked - hours worked by the employee in a given week (call by value)
//  
//**************************************************************/ 
 
float getHours (long int clockNumber) 
{ 
 
    float hoursWorked = 0; /* hours worked in a given week */ 
 
    /* Get Hours for each employee */ 
    printf("\nEnter hours worked by emp # %06li: ", clockNumber); 
    scanf ("%f", &hoursWorked); 
 
    return (hoursWorked); 
} 
 
//**************************************************************/ 
// Function: getOvertime
// 
// Purpose: to calculate overtime hours
// Parameters: hours - total hours worked in a week
//			   STD_WORK_WEEK - a normal 40 hour week
// 
// Returns: the calculated amount of hours worked in a normal work week
//  
//**************************************************************/
 
float getOvertime (float hours)
{	
	float overtime = 0;  /* OT Hours */
	if (hours > STD_WORK_WEEK) /* OT? */
	    overtime = hours - STD_WORK_WEEK;
 
	return (overtime);
}	
 
//**************************************************************/ 
// Function: getGross 
// 
// Purpose: to calculate the gross pay 
// 
// Parameters: overtime- amount of hours worked over 40
//			   hours - total hours worked
//			   wage - normal hourly rate
//             STD_WORK_WEEK - normal 40 hour week
//             OVERTIME_RATE - 1.5 times the normal hourly rate
//
// Returns: total gross pay for the work week
//  
//**************************************************************/
 
float getGross (float hours, float overtime, float wage)
{
 
    float gross;  /* gross pay */
 
    /* if else statement to account for gross hours with or without overtime */
    if (overtime > 0) /* calculate gross pay taking into account for overtime */
    {   
        gross = (STD_WORK_WEEK * wage) + /* regular pay for hours within 40 hour work week */
            ((OVERTIME_RATE * wage) * overtime); /* additional hours with wage increased by constant multiplier */
    }
 
    else /* calculate gross pay of hours up to 40 */
    {
        gross = wage * hours;
    }
 
    return(gross);
}
 
int main ()
 
{
    /* Set up a local variable and initialize the name, clock, and wages of my employees */
    struct employee employeeData[NUM_EMPL] = {
        { "Connie Cobol", 98401, 10.60 },
        { "Mary Apl", 526488, 9.75 },
        { "Frank Fortran", 765349, 10.50 },
        { "Jeff Ada", 34645, 12.25 },
        { "Antone Pascal", 127615, 8.35 }
    };
 
    /* Call various functions needed to read and calculate info */
 
for (int i = 0; i < NUM_EMPL; ++i)
 
    {
 
        /* Function call to get input from user. */
        employeeData[i].hours = getHours (employeeData[i].id_number); 
 
        /* Function call to calculate overtime */ 
		employeeData[i].overtime = getOvertime (employeeData[i].hours);
 
        /* Function call to calculate gross pay */ 
		employeeData[i].gross = getGross (employeeData[i].hours, employeeData[i].overtime, employeeData[i].wage);
 
    }
 
    /* Print the column headers */
	printf("\n------------------------------------------------\n");
 
	printf("CLock# Wage Hours Overtime Gross\n");
 
	printf("------------------------------------------------");
 
    /* Function call to output results to the screen in table format. */
    Output_Results_Screen (employeeData, NUM_EMPL);
 
    return(0); /* success */
 
} /* main */
 