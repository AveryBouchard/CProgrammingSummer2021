struct date
{
    int month;
    int day;
    int year;
};

//function prototype
struct date nextDay(struct date dateVal);

#include <stdio.h>

int main()
{
    //two structure variables
    struct date today, tomorrow;

    //set today to the proper date
    today.day = 22;
    today.year = 2021;
    today.month = 6;

    //this statement ilustratres the ability to pass a 
    //structure to a function and to return one as well

    tomorrow = nextDay(today); //tomorrow updated

    printf("%d/%d/%d\n", tomorrow.month, 
                         tomorrow.day,
                         tomorrow.year);

    return (0);
}

/********************************************************
** Function:  nextDay
**
** Description:  Returns the next day given a date
**
** Parameters:  dateval - a given date
**
** Returns:     dateval - updated next day date
**
*********************************************************/
struct date nextDay(struct date dateVal)
{
    ++dateVal.day;      //add a day
    return (dateVal);   //return updated structure

}