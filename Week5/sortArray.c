/* Program to sort an array of integers in ascending order */

#include <stdio.h>

/* takes an array(a) of n elements */
void sort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; ++i)             /* i = 0 (the first element in the array) up to n-1 (the second to last element in the array */
        for (j = i + 1; j < n; ++j)         /* j = i + 1 (the second element in the array) up to n (the last element in the array) */
            if (a[i] > a[j]){               /* if the first element is bigger than the second element, flip them */
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;                /* this loop continues through every element in the array */
            }
}

int main (void)
{
    int idx;                                                                                /* initialize loop index */
    int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11 };       /* initialize array */
    void sort (int a[], int n);                                                             /* sort prototype */

    printf("The array before the sort:\n");

    for (idx = 0; idx < 16; ++idx)              /* loop through array elements and print each */
        printf("%i ", array[idx]);

    sort(array, 16);                            /* call sort function and pass array and 16 as parameters */

    printf("\n\nThe array after the sort:\n");

    for (idx = 0; idx < 16; ++idx)              /* loop through array elements and print each */
        printf("%i ", array[idx]);

    printf("\n");

    return 0;
}