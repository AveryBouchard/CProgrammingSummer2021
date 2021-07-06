/* employees.h - Common Employee Header File */

/* common types */
struct employee
{
    int id_number;
    float wage;
    float hours;
};

/* funcxtion prototypes */
void printEmp (struct employee * emp_ptr);
void updateEmp (struct employee * emp_ptr, int clock, float wage, float hours);