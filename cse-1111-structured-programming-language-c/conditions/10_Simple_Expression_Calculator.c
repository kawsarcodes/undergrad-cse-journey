/*
Problem: Program that will evaluate simple expressions of the form- <number1> <operator> <number2>; where operators are (+, - , *, /)
Input 
100    /        0
Output
Division:    Zero as divisor is not valid!
*/

#include <stdio.h>

int main() {
    double num1, num2;
    char op;

    if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
        printf("Invalid input.\n");
        return 1;
    }

    if (op == '+') {
        printf("Addition:  %g\n", num1 + num2);
    } else if (op == '-') {
        printf("Subtraction:  %g\n", num1 - num2);
    } else if (op == '*') {
        printf("Multiplication:  %g\n", num1 * num2);
    } else if (op == '/') {
        if (num2 != 0) {
            printf("Division:   %f\n", num1 / num2);
        } else {
            printf("Division:    Zero as divisor is not valid!\n");
        }
    } else {
        printf("Invalid Operator\n");
    }

    return 0;
}