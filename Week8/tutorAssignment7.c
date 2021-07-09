/*********************************************************************
**
** HOMEWORK: #6 Strings
**
** Name: Nathan Goldrick
**
** Class: C Programming
**
** Date: 7/2/21
**
** Description: This program prompts the user for the number of hours
** worked for each employee. It then calculates gross pay
** including overtime and displays the results in table. Functions,
** structures, and strings are used.
**
/**********************************************************************/

/*Define and Includes */

#include <string.h>
#include <stdio.h>

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

void Output_Results_Screen (struct employee *pointer, int size);
void calculate_Overtime (struct employee *pointer, int size);
void get_Gross (float hours, float overtime, float wage);
void getHours (long int clockNumber);
void getOvertime (float hours);
void total_average_results (struct employee *pointer, int size);

/* add your functions here */

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

void Output_Results_Screen ( struct employee *pointer, int size )
{
    int i; /* loop index */

    /* print information about each employee */
    for (i = 0; i < size ; ++i)
    {
        printf("\n %-15s %6li\t%5.2f\t%4.1f\t%4.1f\t%8.2f",
       pointer -> name, pointer -> id_number, pointer -> wage, pointer -> hours,
        pointer -> overtime, pointer -> gross);
    } /* for */

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
    int i; /* loop index */
    float average_wage; /* average hourly rate for all employees */
    float average_hours; /* average hours worked by all employees */
    float average_ot; /* average overtime worked by all employees */
    float average_gross; /* average gross pay to all employees */

    /* print information about each employee */
    for (i = 0; i < size ; ++i)
    
    {
	    total_wage += pointer -> wage; 
		total_hours += pointer -> hours;
		total_ot += pointer -> overtime;
		total_gross += pointer -> gross; 
		
		average_wage = total_wage/ NUM_EMPL; /* calculation for average wage */
    	average_hours = total_hours / NUM_EMPL; /* calculation for average hours */
    	average_ot = total_ot / NUM_EMPL; /* calculation for average overtime hours */
    	average_gross = total_gross / NUM_EMPL; /* calculation for average gross pay */
		
		
    } /* for */
   
    printf("\nTotal:    \t\t\t\t%5.2f\t%4.1f\t%4.1f\t%8.2f", total_wage, total_hours, total_ot, total_gross);
    printf("\nAverage:  \t\t\t\t%5.2f\t%4.1f\t%4.1f\t%8.2f\n", average_wage, average_hours, average_ot, average_gross);
    


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
//			   
// 
// Returns: the calculated amount of hours worked in a normal work week
//  
//**************************************************************/
 
float getOvertime (float hours)
{	
	float overtime = 0;  /* OT Hours */
	if (hours > STD_WORK_WEEK) /* overtime hours calculation */
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
//             
//             
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
    struct employee employeeData[NUM_EMPL] = 
    {
        { "Connie Cobol", 98401, 10.60 },
        { "Mary Apl", 526488, 9.75 },
        { "Frank Fortran", 765349, 10.50 },
        { "Jeff Ada", 34645, 12.25 },
        { "Antone Pascal", 127615, 10.00 }
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
	
	printf("\tName\t\tClock#\tWage\tHours\tOvertime\tGross\n");
	
	printf("------------------------------------------------");
	
    /* Function call to output results to the screen in table format. */
    Output_Results_Screen (employeeData, NUM_EMPL);
    
    printf("\n------------------------------------------------\n");
    
    total_average_results (employeeData, NUM_EMPL);

    return(0); /* success */

} /* main */

