#include <stdio.h>
#include "employees.h"

/* Program using pointer to a structure */

int main ()
{
    struct employee emp;       /* structure */
    struct employee * emp_ptr; /* pointer to structure */

    emp_ptr = &emp; /* pointer to address of structure */


    (*emp_ptr).id_number = 98401; /* works */

    /* or */

    emp_ptr -> id_number = 98401; /* better */

    /* access and set the other two members too */
    emp_ptr->wage = 10.60;
    emp_ptr->hours = 0;

    /* print the employee */
    printf ("\nEmployee changed in main function by our pointer:\n");
    printEmp (emp_ptr);

    /* Update it via a function call */
    updateEmp (emp_ptr, 58734, 14.56, 40.0);

    /* print the updated employee */
    printf ("\nEmployee changed in updateEmp function by our pointer:\n");
    printEmp (emp_ptr);

    return (0);
}