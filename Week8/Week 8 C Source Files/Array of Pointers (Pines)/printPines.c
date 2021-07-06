#include <stdio.h>

/*********************************************************************
* Function:  printPines
*
* Description:  Prints out a list of pine trees stored in an
*               array of pointers.
*
* Parameters:  pines - Array of pointers to pine trees
*              size - number of items to print
*
* Returns:  void
*
**********************************************************************/
void printPines (char * pines[ ], int size)
{
        int i; /* loop and array index */

        /* print all the pines */
        for (i=0; i < size; ++i)
        {
                printf ("\n%s ", pines [i]);
        }

        return;
}