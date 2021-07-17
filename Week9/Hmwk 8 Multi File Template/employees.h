/* employees.h - common constants, types, and function prototypes */

/* define all constants here */
#define SIZE 5
#define STD_HOURS 40.0f
#define OT_RATE 1.5f

/* type to hold employee information */
struct employee
     {
     int id_number;
     float wage;

     /* TODO - Add other members */

     struct employee *next;
     };

/* add function prototypes here if you wish */
void print_list(struct employee *emp1);

/* Add other fucntion prototypes here as needed */