#include <stdio.h>

/*
Number of Walks (BB), Strike Outs (SO), 
Hit by Pitch (HP), Sac Flys (SF), Singles,
Doubles (2B), Triples (3B), and Home Runs (HR)
as well as Number of At Bats (AB).
*/

/*
Total Bases, Batting Average, Home Run Ratio, 
Strike Out Ratio, On Base Percentage, 
and Slugging Average
*/

main()
{
    float totalHits, singles, doubles, triples, homeRuns, walks, strikeOuts, hitByPitch, atBats, sacFlys;

    totalHits = hits(singles, doubles, triples, homeRuns);
}

float hits(float singles, float doubles, float triples, float homeRuns)
{
    int hits = (singles + doubles + triples + homeRuns);

    return hits;
}

int totalBases(float singles, float doubles, float triples, float homeRuns)
{
    int total = (singles + doubles*2 + triples*3 + homeRuns*4);

    return total;
}

float battingAverage(float singles, float doubles, float triples, float homeRuns, float atBats)
{
    int totalHits;

    totalHits = hits(singles, doubles, triples, homeRuns);
    float average = ( totalHits / atBats);

    return average;
}

float homeRunRatio(float homeRuns, float atBats)
{
    float ratio = homeRuns / atBats;

    return ratio;
}

float strikeOutRatio(float strikeOuts, float atBats)
{
    float ratio = strikeOuts / atBats;

    return ratio;
}

float onBasePercentage(float totalHits, float walks, float hitByPitch, float atBats, float sacFlys)
{
    float percentage = (totalHits + walks + hitByPitch) /
                        (atBats + walks + hitByPitch + sacFlys);

    return percentage;
}

float sluggingPercentage(float singles, float doubles, float triples, float homeRuns, float atBats)
{
    float bases, percentage;

    bases = totalBases(singles,  doubles,  triples,  homeRuns);

    percentage = bases / atBats;

    return percentage;
}