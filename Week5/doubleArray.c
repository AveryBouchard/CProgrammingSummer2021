#include <stdio.h>

//***************************************************************
// function - doubleIt
// 
// Description: double the value of any given integer value
// 
// Parameters: number - integer value to double
// 
// Returns: result - the umber doubled
//**************************************************************

int doubleIt (int number)
{
    int result; //variable to hold value of doubled number

    result = number + number; //double it

    return result;
}

//***************************************************************
// Function: doubleArray
// 
// Description: given an array, double the values in each array element
// 
// parameters: someArray - array of integers
//             size - size of the array 
// 
// returns: void
//*****************************************************************

void doubleArray (int someArray[], int size)
{
    int i; // index 

    for (i = 0; i < size; ++i)
    {

        someArray[i] *= 2; //contents changed in calling function

        //no return needed
    
    }    
}

int main()
{
    int i; // index
    int myArray[3] = {10, 20, 30}; //local array
                                                                        //*******************************************
    printf("%i doubled is %i\n", myArray[2], doubleIt(myArray[2]));     // pass one element of array by value
    printf("After call to doubleIt \n\n");                              // this is really just passing an integer value
    printf("myArray[2] = %i \n", myArray[2]);                           // the contents of myArray[2] are unchanged
                                                                        //********************************************
    // simply pass doubleIt any integer value
    printf("\n\n 5 doubled is %i \n\n", doubleIt(5));

    // If you pass an array name, you are passing the array address: &myArray[0]

    // each array element in myArray will get doubled
    doubleArray(myArray, 3);

    printf("After call to doubleArray: \n\n");

    // verify each array element has been doubled
    for (i = 0; i < 3; ++i)
    {
        printf("myArray[%i] = %i \n", i, myArray[i]);
    }
    
    return 0;

}

