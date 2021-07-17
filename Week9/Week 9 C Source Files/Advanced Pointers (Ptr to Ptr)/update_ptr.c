/* use extern to make known the global variables */
extern int x;
extern int y;

/*************************************************************************
**
**  Function:  update_ptr
**
**  Description:  Receives a pointer to pointer and uses it to
**                          update the concents of the pointer it is referencing.
**                          The result is that the pointer will be updated in the
**                          calling function.
**
**                          Pass pointers to pointers to functions to change
**                          the contents of the pointers they are pointing to
**                          in both the called AND calling functions.
**
**  Parameters:  ptr - a pointer to a pointer that points to an integer
**
**  Returns:  void
**
**************************************************************************/

void update_ptr (int ** ptr)
{
    *ptr = &y;  /* this will actually change ptr in main */
}