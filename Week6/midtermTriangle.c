#include <stdio.h>


float triangleArea(float, float);
float trianglePerimeter(float sideA, float sideB, float sideC);


int main()
{

    float area;
    float perimeter;

    area = triangleArea(20, 30);

    printf("\n\n%f\n", area);

    perimeter = trianglePerimeter(3, 4, 5);

    printf("\n%f\n\n", perimeter);

    return 0;

}

/*****************************************************/
// Function: triangleArea
//
// Description: given a base and a height, this function 
//              calculates the area of the triangle
//
// Parameters: float height - the height of the triangle
//            float base - the length of the longest side 
//
// Returns: area of the triangle
/******************************************************/

float triangleArea(float height, float base)
{
    float area;

    area = (height * base) * .5;

    return area;

}

/*****************************************************/
// Function: trianglePerimeter
//
// Description: given the 3 sides of the triangle, this 
//              function calculates the perimeter of the 
//              triangle            
//
// Parameters: sideA, sideB and sideC
//
// Returns: perimeter of the triangle
/******************************************************/

float trianglePerimeter(float sideA, float sideB, float sideC)
{
    float perimeter;

    perimeter = sideA + sideB + sideC;

    return perimeter;
}