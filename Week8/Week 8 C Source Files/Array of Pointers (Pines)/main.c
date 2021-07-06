/* Program containing an array of pointers */

#include <stdio.h>

/* function prototypes */
void printPines (char * pines[ ], int size);

int main ()
{

    static char *pines [ ] =
     {
         "white",
         "yellow",
         "black",
         "red",
         "pitch",
         "Austrian"
     };

    printf("Printing a list of all our pine trees: ");
    printPines (pines, 6);

    printf ( "\n\nThe second pine is %s \n", pines [ 1 ] );
    printf ( "\nThe second char of it is %c \n", *( pines [ 1 ] + 1) );

    return (0);

}