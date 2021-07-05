#include "stdio.h"

int main()
{

    char c = 'q';
    char *charPointer;
    charPointer = &c;

    printf("%c\n", c);
    printf("%li\n", charPointer);
    printf("%li\n", *charPointer);
    printf("%li\n", &c);
    printf("%li\n", &charPointer);

    return 0;
}