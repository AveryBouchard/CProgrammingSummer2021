#include <stdio.h>
#include "presidents.h"

int main ()
{
    int i; /* loop index */

    /* These are my three favorite presidents */
    struct president myPresidents [SIZE] = {
        {"Ronald Reagan", "1981-1989"},
        {"George Washington", "1789-1797"},
        {"Thomas Jefferson", "1801-1809"}
    };

    printf ("\nPrint whatever size the names are, Left Justified \n");
    for (i = 0; i < SIZE; ++i )
    {
        printf ("%s\t\t%s\n",
          myPresidents[i].name,
          myPresidents[i].yearsServed);
    }

    printf ("\n\nTake up a minimum of 20 spaces, Left Justified \n");
    for (i = 0; i < SIZE; ++i )
    {
        printf ("%-20s\t\t%s\n",
          myPresidents[i].name,
      myPresidents[i].yearsServed);
    }

    printf ("\n\nTake up a minimum of 20 spaces, Right Justified \n");
    for (i = 0; i < SIZE; ++i )
    {
        printf ("%20s\t\t%s\n",
          myPresidents[i].name,
      myPresidents[i].yearsServed);
    }

    printf ("\n\nTake up a minimum of 10 spaces, pad as needed, Left Justified \n");
    printf ("... if name is longer, it will still print all characters\n");
    for (i = 0; i < SIZE; ++i )
    {
        printf ("%-10s\t\t%s\n",
          myPresidents[i].name,
      myPresidents[i].yearsServed);
    }

    printf ("\n\nPrint a maximum of 15 characters, pad if needed, Left Justified,");
    printf ("\n... this is good if you need to limit a field size being displayed \n");
    for (i = 0; i < SIZE; ++i )
    {
        printf ("%-15.15s\t\t%s\n",
          myPresidents[i].name,
      myPresidents[i].yearsServed);
    }

    printf ("\n\nPrint a maximum of 20 characters, pad if needed, Left Justified,");
    printf ("\n... Plan for worst caase, so that all field sizes are  being displayed \n");
    for (i = 0; i < SIZE; ++i )
    {
        printf ("%-20.20s\t\t%s\n",
          myPresidents[i].name,
      myPresidents[i].yearsServed);
    }


    return (0);
}