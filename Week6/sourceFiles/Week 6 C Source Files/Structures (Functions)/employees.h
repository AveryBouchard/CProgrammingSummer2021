/* employees.h */

/* Its OK to make the type global, that way all functions can use it */
/* Note that "struct date" is NOT a global variable */
struct date

{

    int month;
    int day;
    int year;
};

void printNextDay (struct date dateval);  /* function prototype */