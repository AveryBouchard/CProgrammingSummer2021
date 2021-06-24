/* date_time.h - commmon date and time constants and types */

struct time
{
    int hour, minutes, seconds;
};

struct date
{
    int month, day, year;
};

struct date_and_time
{
    struct date sdate;
    struct time stime;
};