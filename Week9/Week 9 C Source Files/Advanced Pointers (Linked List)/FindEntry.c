#include <stdio.h>
#include "employees.h"

/***********************************************************************************
**
** Function: findEntry
**
** Description: Using list_ptr as a starting point, examine every entry in
** the list until an entry is found that has an id_number which
** matches the one passed to the function. If found, return a pointer
** to the node, otherwise, return NULL.
**
** Parameters:
**
**     list_ptr - pointer to the beginning of the link list
**     id_number - employee identifier to search
**
** Returns: Pointer to linked list node with the ID (otherwise NULL returned)
**
************************************************************************************/

struct employee * findEntry (struct employee * list_ptr, int id_number)
{

     struct employee * found_it_ptr = list_ptr;  /* set to beginning of list */

    /* search through linked list, return a pointer to the node if the ID found in it */

     for ( ; found_it_ptr; found_it_ptr = found_it_ptr->next)
     {

         if ( found_it_ptr -> id == id_number )
             return ( found_it_ptr );   /* found */

     }

     return ( (struct employee *) NULL );   /* not found, return NULL pointer */

}   /* find entry */