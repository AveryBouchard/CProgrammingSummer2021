#include <stdio.h>


char testGrade(int testScore);

char main()
{
    int test1;

    test1 = testGrade(73);

    printf("%i\n\n", test1);


    return 0;
}




char testGrade(int testScore)
{

    char letterGrade;

    if (testScore >= 90 && testScore <= 100)
        letterGrade = 'A';
        else if (testScore >= 80 && testScore <= 89)
            letterGrade = 'B';
            else if (testScore >= 70 && testScore <= 79)
                letterGrade = 'C';
                else if (testScore >= 60 && testScore <= 69)
                    letterGrade = 'D';
                    else if (testScore >= 0 && testScore <= 59)
                        letterGrade = 'F';
    else
        letterGrade = 'I';


    printf("%c\n", letterGrade);

}