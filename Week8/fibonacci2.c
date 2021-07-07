#include <stdio.h>

int main()
{
    int n1=0, n2=1, n3, i, number;

    printf("Print the number of elements: ");
    scanf("%d", &number);

    printf("\n%d \n%d", n1, n2); //printing 0 and 1

    for(i=2; i<number; ++i)
    {
        n3 = n1 + n2; 
        printf("\n%d", n3);
        n1 = n2;
        n2 = n3;
    }

    return 0;
}