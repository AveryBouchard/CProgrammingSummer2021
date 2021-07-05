#include <stdio.h>

int main()
{

    int i1 = 10;
    int i2;
    int *p1 = &i1;

    //whatever p1 points to is divided by 2

    i2 = *p1 / 2 + 10; //( (*p1)  /  2 ) + 10

    printf("%i", i2);

    return 0;
}