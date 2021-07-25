#include <stdio.h>
#include <string.h>     //for strlen()

int main()
{
    char string[30];    //variable to hold the string
    int idx,            //loop index
        len;            //holds length of string array
    int answer = 0;         //determines whether palindrome has been decided

    printf("Enter a string to check if it's a palindrome: \n");
    scanf("%s", string);

    len = strlen(string); //length of the string

    for(idx=0; idx<len; idx++)
    {
        if(string[idx] != string[len-idx-1])
        {
            answer = 1;
            break;
        }
    }

    if(answer)
        printf("%s is a NOT palindrome\n\n", string);
    else
        printf("%s is a palindrome\n\n", string);

    return(0);
}
