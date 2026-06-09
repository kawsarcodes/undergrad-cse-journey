/*
Problem: Program that will construct an arithmetic menu where choice 4 explicitly halts execution with a designated zero divisor error string when variable b equals zero.
Input 
-5     0     4
Output
Error: Divisor is zero
*/

#include <stdio.h>

int main() {
    float a, b;
    int choice, subCase;

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
        if (b == 0) {
            printf("Error: Divisor is zero\n");
            return 0;
        }

        if (scanf("%d", &subCase) != 1) return 1;

        if (subCase == 1) {
            printf("Quotient: %d\n", intA / intB);
        } else if (subCase == 2) {
            printf("Reminder: %d\n", intA % intB);
        }
    }

    return 0;
}