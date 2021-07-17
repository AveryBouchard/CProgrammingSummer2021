/* employees.h file */

/* types */
struct employee
{
    int id;
    float wage;
    struct employee *next;
};


/* prototypes */
struct employee * findEntry (struct employee * list_ptr, int id_number);
void print_list (struct employee *emp1);