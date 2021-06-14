#include <stdio.h>

void gcd(int u, int v){

    int temp;

    printf("The greatest common divisor of %i and %i is ", u, v);

    while (v != 0){
        temp = u % v;
        u = v;
        v = temp;
    }

    printf("%i\n", u);
}

int main(void){
    gcd(50, 150);
    gcd(1026, 405);
    gcd(86, 204);
}