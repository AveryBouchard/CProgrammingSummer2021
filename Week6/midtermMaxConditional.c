#include <stdio.h>

int main()
{
    int v = 9, w = 8, x = 7, y = 4, z = 1, max;

    max = v > w ? v > x ? v > y ? v > z ?
            w > x ? w > y ? w < z ?
            x > y ? x > z ?
            (y > z ? : v ): w : x : y : z);

    printf("%i\n\n", max);
}