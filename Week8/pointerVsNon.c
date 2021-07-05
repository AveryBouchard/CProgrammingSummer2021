#include <stdio.h>

int main()
{

    int array_sum_pnt(int number[], int elements);

    int result;
    int numbers[] = {4, 2, 3, 5, 6, 4, 3, 2, 1, 5, 3, 6, 4};

    result = array_sum_pnt(numbers, 13);

    printf("%i\n", result);
}

//Non Pointer Solution
int array_sum(int array[], int num_of_elements)
{
    int i;
    int sum = 0;

    for (i = 0; i < num_of_elements; ++i)

        sum += array[i];

    return sum;
}

// Pointer Solution
int array_sum_pnt(int *array, int num_of_elements)
{
    int sum = 0;                              // sum of array of elements
    int *array_end = array + num_of_elements; //end of array

    for (; array < array_end; ++array)

        sum += *array; //big savings in runtime

    return sum;
}