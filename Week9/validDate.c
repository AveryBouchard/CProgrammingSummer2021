#include <stdio.h>

void validDate(int *date);

int main()
{
    int date[3] = {2, 29, 2000};

    validDate(date);

    return(0);
}

void validDate(int *date)
{

    if(date[0]<1 || date[0]>12)
        printf("Invalid Month");
    else if(date[1]<1 || date[1]>31)
        printf("Invalid Day");
    else if(date[2]<1)
        printf("Invalid Year");
    else if (date[0] == 2 && date[2] % 4 == 0 && date [1] > 28)
        printf("Invalid - Leap Year");
    else
        printf("The is a valid date");
}