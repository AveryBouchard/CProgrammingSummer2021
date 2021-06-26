#include <stdio.h>
#include <ctype.h>


int gradesTotal(char grades[], int length);

int main()
{
    char grades[] = {'b', 'b', 'b', 'a', 'B', 'B', 'q', 'C', 'D', 'F', 'A', 'c'};

    gradesTotal(grades, 12);
}


/*****************************************************/
// Function: gradesTotal(char arrayOfGrades[], int lengthOfArray)
//
// Description: takes an array of letter grades and prints out how many of each letter
//              are contained in the array.          
//
// Parameters: charGrades[] - an array of letter grades
//             int lenth - the length of the array to pass to the for loop
//
// Returns: none - prints the result to the console.
/******************************************************/

int gradesTotal(char grades[], int length)
    {


        int grade;
        int idx; // index
        int a = 0;
        int b = 0;
        int c = 0; 
        int d = 0; 
        int f = 0;
        int i = 0;

        for (idx = 0; idx < length; ++idx)
            {grade = toupper(grades[idx]);

                switch (grade)
                {
                    case 'A':
                        a += 1;
                        printf("That was an A\n");
                        break;
                    
                    case 'B':
                        b += 1;
                        printf("That was a B\n");
                        break;

                    case 'C':
                        c += 1;
                        printf("That was a C\n");
                        break;

                    case 'D':
                        d += 1;
                        printf("That was a D\n");
                        break;

                    case 'F':
                        f += 1;
                        printf("That was an F\n");
                        break;

                    default:
                        i += 1;
                        printf("That was invalid\n");
                        break;
                }
            }

        printf("In this array, there are %i A's, %i B's, %i C's, %i D's, %i F's and %i grades were invalid.", a, b, c, d, f, i);
    

    }