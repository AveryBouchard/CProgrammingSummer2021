#include <stdio.h>

int main(){

    int i; //loop index
    int values [5] = {10, 567, 56, 23, 78}; //initialize array

    //loop and print contents and address of each array element

    printf("Address\t\tArray Element\tContents\n\n");
    for (i=0; i<5; i++){
        //print address in hexadecimal
        printf("%lx \tValues [%i] \t%i \n", &values[i], i, values[i]);
    }

    int foo[5];
    foo [5]=12;

    printf("%i\n\n", foo[5]);

    return(0);
}