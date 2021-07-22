#include <stdio.h>

#define T 10
#define J 10
#define Q 10
#define K 10

char A = 1;

int handScore(int card1, int card2);

int main()
{

    int firstHand;

    
    firstHand = handScore(8, T);

    printf("%i\n\n", firstHand);


    return(0);
}


int handScore(int card1, int card2)
{
    int score;

    if (card1 > 11)
        printf("Invalid Card1");

    if (card2 > 11)
        printf("Invalid Card2");

    if (card1 == 1)
        card1 = 11;

    score = card1 + card2;

    return score;
}
