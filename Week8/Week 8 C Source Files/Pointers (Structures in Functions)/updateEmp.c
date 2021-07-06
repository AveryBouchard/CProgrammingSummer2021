#include "employees.h"

/*********************************************************************
* Function:  updateEmp
*
* Description:  Updates an employee using a pointer to a structure
*
* Parameters:  emp_ptr - Pointer to the employee structure variable
*              clock - employee clock number value
*              wage - employee weekly wage value
*              hours - employee hours worked value
*
* Returns:  void (but note the structure pointed to will be updated)
*
**********************************************************************/
void updateEmp (struct employee * emp_ptr, int clock, float wage, float hours)
{
    /* update employee using the passed  */
    /* pointer to the structure variable */
    emp_ptr -> id_number = clock;
    emp_ptr->wage = wage;
    emp_ptr->hours = hours;

    return;
}