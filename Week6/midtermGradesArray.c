#include <stdio.h>


int gradesTotal(char grades[], int length);

int main()
{
    char grades[] = {'A', 'b', 'b', 'a', 'B', 'B', 'q', 'C', 'D', 'F', 'A', 'A'};

    gradesTotal(grades, 12);
}

int gradesTotal(char grades[], int length)
    {
    int idx; // index
    int a = 0; 
    int b = 0;
    int c = 0;
    int d = 0;
    int f = 0;
    int i = 0;

    for (idx = 0; idx < length; ++idx)
        {
            if (grades[idx] == 'a' || grades[idx] == 'A')
                a += 1;
                else if (grades[idx] == 'b' || grades[idx] == 'B')
                    b += 1;
                    else if (grades[idx] == 'c' || grades[idx] == 'C')
                        c += 1;
                        else if (grades[idx] == 'd' || grades[idx] == 'D')
                            d += 1;
                            else if (grades[idx] == 'f' || grades[idx] == 'F')
                                f += 1;
                                else
                                    i += 1;
            }

    printf("In this array, there are %i A's, %i B's, %i C's, %i D's, %i F's and %i grades were invalid.", a, b, c, d, f, i);
    

    }