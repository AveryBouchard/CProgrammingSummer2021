#include <stdio.h>
#include <string.h>

int wordsInString(char *sentence);

int main()
{
    int count = 0;
    char sentence[200] = "This is a sentence that I would like to count the number of words in";

    count = wordsInString(sentence);

    printf("%i", count);

    return(0);
}

int wordsInString(char *sentence) //passes a pointer to the sentence variable
{
    int i, //variable to hold the current character to decide whether it is a letter, a space or a Null terminator
        count = 1; //variable to hold the number of words counted

    for(i=0;sentence[i]!='\0';i++)
    {
        if (sentence[i] == ' ' && sentence[i+1] != '\0') //if the pointer is at a space, and the next character is not null terminator
            ++count;                                       //increment count variable.
    }

    return(count);
}