#include <stdio.h>
#include <stdlib.h>

struct stringCharacteristics
{

    char string[101];
    int length;
    int upperLetters;
    int lowerLetters;
    int digits;
    int blankSpaces;
    int nonAlphaCharacters;

};

void getCharacteristics(struct stringCharacteristics * pointer);

int main()
{

    struct stringCharacteristics string;

    getCharacteristics(string);

    return 0;
}

void getCharacteristics(struct stringCharacteristics * pointer)
{

    int idx;

    printf("Type in a string to get the characteristics (up to 100 characters): ");
    scanf("%s", &pointer->string);

    pointer->length = strlen(pointer->string);

    for (idx = 0; idx < pointer->length; idx++)
        {
            if (pointer->string[idx] >= 'A' && pointer->string[idx] <= 'Z')
                pointer->upperLetters++;

            else if (pointer->string[idx] >= 'a' && pointer->string[idx] <= 'z')
                pointer->lowerLetters++;

            else if (pointer->string[idx] >= '0' && pointer->string[idx] <= '9')
                pointer->digits++;

            else if (pointer->string[idx] == ' ')
                pointer->blankSpaces++;

            else 
                pointer->nonAlphaCharacters++;
        }

    printf("%i", pointer->upperLetters);

    return;
}

