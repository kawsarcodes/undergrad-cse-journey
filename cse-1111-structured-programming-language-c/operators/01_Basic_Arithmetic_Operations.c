/*
Problem: Program that will take two numbers X and Y as inputs, then calculate and print the values of their addition, subtraction, multiplication, division (quotient and reminder).
Input 
5     10
Output
Addition: 15
Subtraction: -5
Multiplication: 50
Quotient : 0
Reminder: 5
*/

#include <stdio.h>

int main() {
    float x, y;
    
    if (scanf("%f %f", &x, &y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    
    printf("Addition: %.1f\n", x + y);
    printf("Subtraction: %.1f\n", x - y);
    printf("Multiplication: %.1f\n", x * y);
    
    int intX = (int)x;
    int intY = (int)y;
    
    if (intY != 0) {
        printf("Quotient : %d\n", intX / intY);
        printf("Reminder: %d\n", intX % intY);
    } else {
        printf("Quotient : Undefined\nReminder: Undefined\n");
    }
    
    return 0;
}