#include <stdio.h>

int main()
{
    int a = 10;

    int *int_ptr;

    int_ptr = &a;

    //Addresses in memory are very large, just using %i won't always work.
    //hexadecimal format is a good choice (%lx)

    printf("%i \n%lx \n%lx \n%lx \n%i \n", a, &a, int_ptr, &int_ptr, *int_ptr);

    return 0;
}