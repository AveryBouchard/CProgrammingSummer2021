/* use extern to make known the global variables */
extern int x;
extern int y;

/*************************************************************************
**
**  Function:  no_update_ptr
**
**  Description:  Receives a pointer and updates it.   However, the
**                          contents of the pointer while changed in this
**                          function remain unchanged in the calling function.
**                          This shows that pointers are passed BY VALUE.
**
** Parameters:  ptr - a pointer to an integer
**
** Returns:  void
**
**************************************************************************/

void no_update_ptr (int * ptr)
{
    ptr = &y;  /* no change to ptr in main */
}