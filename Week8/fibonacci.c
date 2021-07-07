#include <stdio.h>

//fibonacci sequence - 1,2,3,5,8,13,21,34.....
void main()
{
    long int first = 0;
    long int second = 1;
    long int fib;
    int i;
    char dot = '.';
    char dots[3000];

    for (i = 0; first < 1000; ++i)
    {

        fib = first + second;
        first = second;
        second = fib;

        for (i = 0; i < fib; ++i)
        {
            printf("%c", dot);
        }

        printf("\n________________________________________________________________________________________________________________\n");
    }

    return;
}
