/* employees.h - common constants, types, and function prototypes for employees */

#define SIZE 3

/* struct type for an employee */
struct employee
{
    int id;
    float wage;
    float hours;
};

/* Function Prototypes */
void getHours (struct employee * ptr, int size);
void printData (struct employee * ptr, int size);