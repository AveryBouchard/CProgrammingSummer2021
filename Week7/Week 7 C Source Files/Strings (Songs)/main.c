// Lyrics from David Bowie's Heroes
#include <stdio.h>
#include <string.h>
#include "songs.h"

int main ()
{

    // You can store many sentences in one string, use
    // the continuation character (the "\") after each line. You
    // can add new lines and other special characters as needed
    // to get the printing effect you need.

    char song [SONG_SIZE]; /* hold a song */that

    printf ("\nPrint the Chorus and Verse 1 of David Bowie's Heroes:\n");
    printLyrics (heroes_chorus);
    printLyrics (heroes_verse1);

    /* copy entire song into a sring variable and print it */
    printf ("\n\nThe entire song of David Bowie's Heroes:\n");
    strcpy (song, heroes_chorus);
    strcat (song, heroes_verse1);
    strcat (song, heroes_refrain1);
    strcat (song, heroes_verse2);
    strcat (song, heroes_refrain2);
    printLyrics (song);

    printf ("\n\nTotal characters in David Bowie's Heroes Song is: %li\n", 
            strlen(song));

    return (0);
}