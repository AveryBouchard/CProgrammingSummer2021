#include <stdio.h>

int main()
{
    char c = 'Q';        //simple char
    char *char_ptr = &c; //pointer

    printf("%c %c\n", c, *char_ptr);

    //always make sure a pointer contains an address before
    //referencing it.
    *char_ptr = 'R';

    printf("%c %c\n", c, *char_ptr);

    return 0;
}