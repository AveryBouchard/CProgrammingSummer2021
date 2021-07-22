#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void legalWord();

int main()
{

    legalWord();

    return 0;
}

void legalWord()
{

    int idx, len, count = 0, countY = 0;
    char word[20], upperLetter;

    printf("Input a word you want to check is legal: ");
    scanf("%s", word);

    len = strlen(word);

    for (idx = 0; idx < len; idx++)
    {

        upperLetter = toupper(word[idx]);

        if (upperLetter == 'Y')
            countY++;
        if (upperLetter == 'A' || upperLetter == 'E' || upperLetter == 'I' ||
            upperLetter == 'O' || upperLetter == 'U')
            count++;

    }

    printf("Count = %i\n\nCountY = %i\n\n", count, countY);

    if (count != 0 || countY != 0)
        printf("That is a legal word.");
    else
        printf("That is NOT a legal word!");

    return;
}