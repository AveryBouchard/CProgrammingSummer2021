#include <stdio.h>

struct name
{
    char first[30];
    char middle;
    char last[50];
};

struct date
{
    int month;
    int day;
    int year;
};

struct country
{
    char country[56];
    char nationality[20];
    char countryAbbreviation[3];
};

struct passport
{
    struct name user;
    char passportNumber[9];
    struct date birthdate;
    struct date dateOfExpiration;
    struct date dateOfIssue;
    struct country issuingCountry;
    struct country nationality;
    struct country placeOfBirth;
    char passportType[1];
    struct country countryVisited;
};