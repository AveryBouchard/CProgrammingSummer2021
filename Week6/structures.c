struct date 
{
    int day;
    int month;
    int year;
};

#include <stdio.h>

int main()
{
    struct date today;

    today.day = 22;
    today.month = 6;
    today.year = 2021;

    printf("%d/%d/%d \n", today.month, today.day, today.year - 2000);

    return 0;
}