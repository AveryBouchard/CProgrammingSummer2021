#include <stdio.h>

struct employee
{
    int id;
    float wage, hours;
};

int main()
{
    struct employee emp;         //structure
    struct employee *empPointer; //pointer to structure

    empPointer = &emp; //pointer to address of structure

    (*empPointer).id = 98401; //this works

    //or

    empPointer->id = 98401; //but this is better

    //access and set the other 2 members too
    empPointer->wage = 10.60;
    empPointer->hours = 0;

    return 0;
}