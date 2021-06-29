/* employees.h - common employee constants, types, and prototypes */

/* constants */
#define SIZE 5

/* types */
struct employee
{
    char first_name [20]; /* First name */
    char last_name [20];  /* Last name */
};

/* function protothpes */
void printNames (struct employee myNames [ ] );