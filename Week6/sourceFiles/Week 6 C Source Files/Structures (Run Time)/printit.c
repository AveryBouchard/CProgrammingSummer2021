#include <stdio.h>

/* this is needed to let this function know about the global variable */
/* so it can compile.  It will be resolved during the linking process */
extern int globalvar;

/*************************************************************
**
** Function - printit
**
** Description - Just increments and prints a set of local,
**               static, and global variables
**
** Parameters:  none
**
** Returns:  void
**
**************************************************************/

void printit ()
{
    static int staticvar = 2;  /* static initialized only once */
                               /* value is always held in memory */

    int autovar = 2; /* local variable within printit */

    globalvar++;
    staticvar++;
    autovar++;

    /* Time line 2 */

    printf("globalvar = %d \n",   globalvar);
    printf("staticvar = %d \n",   staticvar);
    printf("autovar   = %d \n\n", autovar);

} /* printit */