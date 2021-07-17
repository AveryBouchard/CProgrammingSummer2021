#include <stdio.h>
#include "myFunctions.h"

/* global variables */
int x = 10;
int y = 20;


int main ()

{
    int a, c, *ptr;  /* two integers and a pointer */
    float b;         /* floating point number */
    ptr = &x;        /* set ptr to glabal value */

    /* initialize */
    a = 0;
    b = 0;
    c = 0;

    /* call somefunc and see what changes, not that */
    /* the addres of b and c are passed, but not a  */
    somefunc(a, &b, &c);

    /* Note that only b and c were updated, not a */
    printf ("a = %d, b = %f, c = %d \n", a, b, c);

    printf ("before calls, *ptr = %d\n", *ptr);

    /* nothing updated here */
    no_update_ptr (ptr);

    printf ("*ptr = %d after call to no_update_ptr \n", *ptr);

    /* this will update the ptr */
    update_ptr (&ptr);

    printf ("*ptr = %d after call to update_ptr \n", *ptr);

    return (0);

}