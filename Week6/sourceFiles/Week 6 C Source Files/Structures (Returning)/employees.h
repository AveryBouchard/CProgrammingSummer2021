/* employees.h - commmon constants, types, and function prototypes */

struct date
{
    int month;
    int day;
    int year;
};

/* function prototype */
struct date nextDay (struct date dateval);