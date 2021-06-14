#include <stdio.h>

int square(number){

    int result;

    result = number * number;

    return result;
}

void main(){

    int value;

    printf("Enter a number to square: ");
    scanf("%i", &value);

    printf("\n%i squared is %i\n\n", value, square(value));

    return;

}