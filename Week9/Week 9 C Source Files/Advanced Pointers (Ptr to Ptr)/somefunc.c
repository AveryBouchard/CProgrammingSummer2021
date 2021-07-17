/*************************************************************************
**
**  Function:  somefunc
**
**  Description:  Receives a simple integer, a float pointer,
**                       and an integer pointer.  Shows that only
**                       pointer variables will update corresponding items
**                       they are pointing to in the Calling Function.
**
**  Parameters:  a - simple integer value
**                        b - pointer to a float
**                        c - pointer to an integer
**
**  Returns:  void
**
**************************************************************************/
void somefunc(int a, float *b, int *c)
{
   a = 1;
   *b = 2.2;
   *c = 3;
}