/* Add File Header from our class Coding Standards here */

#include <stdio.h>

/* constants to use */
#define SIZE 5 /* number of employees to process */

/* add other constants here ... */
int idx; /* loop index */
float gross;      /* gross pay for week (wage * hours) */ 
float hours;      /* number of hours worked per week */ 
const float STD_HOURS = 40; /* making a 40 hour constant work week */
const float OT_rate = 1.5 ; /* setting the overtime pay rate of 1.5 times the wage */
float OT_hours[SIZE] = {};  /* any hours worked over the standard 40 hour work week */
float OT_gross[SIZE] = {};  /* OT_hours * OT_rate */

long int clock_number [SIZE] = {98401, 526488, 765349, 34645, 127615};
float hourly_pay [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35};

int main()
{
    /* Declare variables needed for program.      */
    /* Recommend an array for clock, wage, hours, */
    /* ... and overtime and gross.                */
    /* Its OK to pre-fill clock and wage values   */
    /* ... or you can prompt for them.            */

    /* unique employee identifier */
    long int clock_number [SIZE] = {98401, 526488,
                                    765349, 34645, 127615}; 
    int count; /* loop index */
    
    /* hourly wage for each employee */
    float hourly_pay [SIZE] = {10.6, 9.75, 10.5,
                               12.25, 8.35}; 

    /* Process each employee one at a time */
    for (count = 0; count < SIZE; count++)
    {

        /* Prompt and Read in hours worked for employee */
	printf ("Enter the number of hours the employee worked: \n"); 
    scanf ("%f", &hours);
    
        /* Calculate overtime and gross pay for employee */
	
	if (hours > STD_HOURS)
        {
         	OT_hours = hours - STD_HOURS; /* determine number of OT hours worked */
        	OT_gross = OT_hours * OT_rate * hourly_pay; /* determine total of gross from OT */
        }
        else 
        {
        	OT_hours = 0;
        }
    }

    /* Print a nice table header */

    /* Access each employee and print to screen or file */
    for(count = 0; count < SIZE; count++)
    {
         
    for (i=0; i < 5; ++i)
    {
    printf("values [%count] = %count\n", count, values [count]);

              }/* Print employee information from your arrays */
    }

    return(0);
}