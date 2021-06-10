#include <stdio.h>

int main(){

    int i;
    int values [5] = {2, 4, 6};

    for(i=0; i<5; i++){
        printf("values [%i] = %i\n", i, values[i]);
    }
    return(0);
}

//any value in an array that isn't initialized is set as 0