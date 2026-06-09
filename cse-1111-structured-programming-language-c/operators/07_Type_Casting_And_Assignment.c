
/*
Problem: Program that will perform floating to integer and integer to floating conversions using Assignment operation and Type casting
Input 
-150      123.125
Output
Assignment:   123.125000 assigned to an int produces 123
Assignment:  -150 assigned to a float produces -150.000000
Type Casting: (float) -150 produces -150.000000
Type Casting: (int) 123.125 produces -123
*/

#include <stdio.h>

int main() {
    int intInput;
    float floatInput;
    
    if (scanf("%d %f", &intInput, &floatInput) != 2) {
        return 1;
    }
    
    int assignedToInt = floatInput;
    float assignedToFloat = intInput;
    
    printf("Assignment:   %f assigned to an int produces %d\n", floatInput, assignedToInt);
    printf("Assignment:  %d assigned to a float produces %f\n", intInput, assignedToFloat);
    
    printf("Type Casting: (float) %d produces %f\n", intInput, (float)intInput);
    printf("Type Casting: (int) %f produces %d\n", floatInput, (int)floatInput);
    
    return 0;
}