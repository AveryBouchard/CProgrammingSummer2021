//******************************************************* 
// 
// Homework: 1 (Chapter 4/5) 
// 
// Name: Nathan Goldrick
// 
// Class: C Programming, Summer 2021 
// 
// Date: 6/2/2021 
// 
// Description: Program which determines gross pay and outputs 
// be sent to a designated file.   This version does not use file pointers
// 
// 
//******************************************************** 
 
#include <stdio.h>  
#define SIZE (5)

int main() 
{ 
    
    int count; /* loop index */
    float gross;  
    float wage;/* gross pay for week (wage * hours) */ 
    float hours;      /* number of hours worked per week */ 
    const float STD_HOURS = 40; /* making a 40 hour constant work week */
	const float OT_rate = 1.5 ; /* setting the overtime pay rate of 1.5 times the wage */
	float OT_hours;  /* any hours worked over the standard 40 hour work week */
	float OT_gross;  /* OT_hours * OT_rate */
	long int clockNumber [SIZE] = {98401, 526488, 765349, 34645, 127615};
	float hourlyWage [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35};
 
	/* title results */
    printf ("\n\t\tJ. Nathan Goldrick, C Programming, Second Homework Assignment\n\n"); 
    printf ("\t----------------------------------------------------------\n"); 
 
    /* Outline instructions for employees/users */ 
	printf ("This is a program to calculate gross pay.\n"); 
    printf ("You will be prompted for employee data.\n\n"); 
 
    /*loop gross pay calculation for number of employees that were input*/
    for (count = 0; count < SIZE; count++) 
    { 
 
        /* Prompt for input values from the screen */ 
        printf ("Enter the number of hours the employee worked: \n"); 
        scanf ("%f", &hours); 
 
        if (hours > STD_HOURS)
        {
         	OT_hours = hours - STD_HOURS; /* determine number of OT hours worked */
        	OT_gross = OT_hours * OT_rate * hourlyWage[count]; /* determine total of gross from OT */
        }
        else 
        {
        	OT_hours = 0;
        }
 
        gross = hourlyWage[count] * (hours - OT_hours) + OT_hours * OT_rate; /* calculate gross pay*/
 
        /* print out employee information */ 
        printf ("\t----------------------------------------------------------\n");  
        printf ("\tClock # Wage Hours OT Gross\n"); 
        printf ("\t----------------------------------------------------------\n"); 
 
        printf ("\t%06li %5.2f %5.1f % 5.1f %7.2f\n\n",clockNumber[count], hourlyWage[count], hours, OT_hours, gross); 
    } /* end of the loop */
 
    return (0); /* success */ 
 
} /* main */