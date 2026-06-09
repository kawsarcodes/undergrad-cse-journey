/*
Problem: Program that will construct a menu for performing arithmetic operations choice 1 to 4 for addition, subtraction, multiplication, division (quotient) respectively.
Input 
-5     10.5     4
Output
Quotient: 0
*/

#include <stdio.h>

int main() {
    float a, b;
    int choice;

    if (scanf("%f %f", &a, &b) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    if (scanf("%d", &choice) != 1) {
        return 1;
    }

    int intA = (int)a;
    int intB = (int)b;

    if (choice == 1) {
        printf("Addition: %g\n", a + b);
    } else if (choice == 2) {
        printf("Subtraction: %g\n", a - b);
    } else if (choice == 3) {
        printf("Multiplication: %g\n", a * b);
    } else if (choice == 4) {
        if (intB != 0) {
            printf("Quotient: %d\n", intA / intB);
        } else {
            printf("Division by zero error.\n");
        }
    } else {
        printf("Invalid Choice\n");
    }

    return 0;
}