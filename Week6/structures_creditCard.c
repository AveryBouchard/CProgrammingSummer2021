#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
};

struct customerName
{
    char first[50];
    char middle[50];
    char last[100];
};

struct creditCard
{
    char cardNumber[20];
    struct customerName customer;
    struct date startDate;
    struct date expirationDate;
};

struct creditCard myCreditCards[1000];